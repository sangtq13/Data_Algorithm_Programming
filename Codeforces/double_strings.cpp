#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    map<char, TrieNode*> children;
    bool is_word;
};

TrieNode* BuildTrie(vector<string> words) {
    TrieNode* root = new TrieNode();
    for (auto& word : words) {
        TrieNode* cur = root;
        for (auto& w : word) {
            if (cur->children.find(w) == cur->children.end()) {
                cur->children[w] = new TrieNode();
            }
            cur = cur->children[w];
        }
        cur->is_word = true;
    }
    return root;
}

bool IsWord(TrieNode* root, string word) {
    TrieNode* cur = root;
    for (auto& w : word) {
        if (cur->children.find(w) == cur->children.end()) {
            return false;
        }
        cur = cur->children[w];
    }
    if (cur->is_word) return true;
    
    return false;
}

// Using Trie method
// Time complexity: O(n)
// Space complexity: O(n)
void Solution1(vector<string> words) {
    TrieNode* root = BuildTrie(words);
    string result = "";
    for (auto& word : words) {
        TrieNode* cur = root;
        bool check = true;
        for (int i = 0; i < word.size(); ++i) {
            cur = cur->children[word[i]];
            if (cur->is_word && IsWord(root, word.substr(i+1))) {
                check = false;
                result.push_back('1');
                break;
            }   
        }
        if (check) result.push_back('0');
    }

    cout << result << endl;
}

// Using Set method
// Time complexity: O(n)
// Space complexity: O(n)
void Solution2(vector<string> words) {
    set<string> s;
    string result = "";
    for (auto& word : words) {
        s.insert(word);
    }
    for (auto& word : words) {
        bool check = true;
        for (int i = 0; i < word.size(); ++i) {
            if (s.find(word.substr(0, i+1)) != s.end() && s.find(word.substr(i+1)) != s.end()) {
                result.push_back('1');
                check = false;
                break;
            } 
        }
        if (check) result.push_back('0');
    }
    
   cout << result << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int size;
        cin >> size;
        vector<string> test;
        for (int i = 0; i < size; ++i) {
            string s;
            cin >> s;
            test.push_back(s);
        }
        Solution1(test);
        Solution2(test);
    }
    return 0;
}
