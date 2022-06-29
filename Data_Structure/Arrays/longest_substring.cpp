class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = s.size();
        if (l == 0) return 0;
        unordered_map<char, int> m;
        int start = 0;
        int longest = 1;
        for (int i = 0; i < l; ++i) {
            if (m.find(s[i]) == m.end()) {
                m[s[i]] = i;
            }
            else {
                cout << start << " " << i << std::endl;
                longest = max(longest, i-start);
                for (int j = start; j < i; ++j) {
                    if (s[j] != s[i]) {
                        m.erase(s[j]);
                    }
                    else {
                        start = j+1;
                        break;
                    }
                }
                m[s[i]] = i;
            }
        }
        if (start != l-1) {
            longest = max(longest, l-start);
        }
        return longest;
    }
};
