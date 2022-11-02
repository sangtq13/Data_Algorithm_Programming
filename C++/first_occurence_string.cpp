#define ll long long
const ll MOD = 1000000003;
const int base = 31;
class Solution {
public:
    // Time complexity: O(m + n)
    // Space complexity: O(m)
    int strStr(string haystack, string needle) {
        int n = needle.size();
        int s = haystack.size();
        ll POW[s+1];
        ll hash[s+1];
        if (n > s) return -1;
        POW[0] = 1;
        for (int i = 1; i < s; ++i) {
            POW[i] = (POW[i-1] * base) % MOD;
        }
        hash[0] = 0;
        for (int i = 1; i <= s; ++i) {
            hash[i] = (hash[i-1] * base + haystack[i-1] - 'a' + 1) % MOD;
        }
        
        ll hash_needle = 0;
        for (int i = 0; i < n; ++i) {
            hash_needle = (hash_needle * base + needle[i] - 'a' + 1) % MOD;
        }
        
        for (int i = 0; i < s-n+1; ++i) {
            ll hash_h = (hash[i+n] - hash[i] * POW[n] + MOD * MOD) % MOD;
            if (hash_h == hash_needle) {
                return i;
            }
        }
        return -1;
    }
};
