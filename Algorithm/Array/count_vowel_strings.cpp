class Solution {
public:
    // Time complexity: O(n)
    // Space complexity: O(n)
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        int count[100001] = {0};
        unordered_map<char, bool> m;
        vector<int> ret;
        // 'a', 'e', 'i', 'o', 'u'
        m['a'] = true;
        m['e'] = true;
        m['i'] = true;
        m['o'] = true;
        m['u'] = true;
        
        for (int i = 0; i < n; ++i) {
            if (m.find(words[i][0]) != m.end() && m.find(words[i][words[i].size()-1]) != m.end()) {
                count[i+1] = count[i] + 1;
            }
            else {
                count[i+1] = count[i];
            }
        }

        for (auto q : queries) {
            int left = q[0];
            int right = q[1];
            if (left == 0) {
                ret.push_back(count[right+1]);
            }
            else {
                ret.push_back(count[right+1] - count[left]);
            }
        }
        return ret;
    }
};
