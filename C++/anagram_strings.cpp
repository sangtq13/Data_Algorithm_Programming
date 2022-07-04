class Solution {
public:
    bool compare(int a[], int b[], int n) {
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) return false;
        }
        
        return true;
    }
    
    // Time complexity: O(n)
    // Space complexity: O(k)
    vector<int> findAnagrams(string s, string p) {
        int ks[26] {0};
        int kp[26] {0};
        vector<int> ret;
        int ls = s.size();
        int lp = p.size();
        if (ls < lp) return {};
        
        for (int i = 0; i < lp; ++i) {
            ks[s[i] - 'a'] += 1;
            kp[p[i] - 'a'] += 1;
        }
        
        if (compare(ks, kp, 26)) ret.push_back(0);
        for (int i = 1; i < ls - lp + 1; ++i) {
            ks[s[i-1] - 'a'] -= 1;
            ks[s[i+lp-1] - 'a'] += 1;
            if (compare(ks, kp, 26)) {
                ret.push_back(i);
            }
        }
        
        return ret;
    }
};
