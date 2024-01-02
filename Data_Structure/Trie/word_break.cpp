struct Trie {
    bool is_key;
    unordered_map<char, Trie*> children_map;
};
bool dp[301];
class Solution {
public:
    bool search (Trie* root, string& s, int current_pos) {
        if (current_pos == s.size()) {
            return true;
        }
        Trie* cur = root;
        for (int i = current_pos; i < s.size(); ++i) {
            if (cur->children_map.find(s[i]) == cur->children_map.end()) return false;
            cur = cur->children_map[s[i]];
            if (dp[i] == true) continue;
            if (cur->is_key) {
                // printf("current_pos %d cur->is_key %d\n",current_pos, i);
                bool ret = search(root, s, i+1);
                if (ret) {
                    return true;
                }
                else {
                    // printf("i %d\n", i);
                    dp[i] = true;
                }
            }
        }
        return false;
    }

    // Time complexity: O(n)
    // Space complexity: O(n)
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp, false, sizeof(bool) * 301);
        Trie* root = new Trie;
        for (auto &word : wordDict) {
            Trie * cur = root;
            for (auto &w : word) {
                if (cur->children_map.find(w) == cur->children_map.end()) {
                    Trie* node = new Trie;
                    node->is_key = false;
                    cur->children_map.insert({w, node});
                    
                }
                cur = cur->children_map[w];
            }
            cur->is_key = true;
        }
        bool ret = search(root, s, 0);
        return ret;
    }
};
