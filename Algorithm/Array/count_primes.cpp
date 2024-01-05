class Solution {
public:
    // Time complexity: O(n)
    // Space complexity: O(n)
    int countPrimes(int n) {
        if (n == 0 || n == 1) return 0;
        bool p[n];
        memset(p, true, sizeof(bool) * n);
        p[0] = false;
        p[1] = false;
        int ret = 0;
        for (long long i = 2; i < n; ++i) {
            if (p[i]) {
                ret++;
                for (long long k = i * i; k < n; k += i) {
                    p[k] = false;
                }
            }
        }
        return ret;
    }
};
