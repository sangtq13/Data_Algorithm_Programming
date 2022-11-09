#define ll long long
class Solution {
public:
    // Time complexity: O(logn)
    // Space complexity: O(logn)
    double myPow(double x, ll n) {
        if (n == 0) return 1;
        int sign = 1;
        if (n < 0) {
            n *= (-1);
            sign = -1;
        }
        unordered_map<int, double> cache;
        cache[1] = x;
        if (sign == -1) {
            cache[1] = 1 / x;
        }
        ll m = 0;
        vector<int> exp;
        ll i = 1;
        double ret = 1;
        while (i <= n) {
            if (i * 2 > n) {
                if (i > m) m = i;
                exp.push_back(i);
                n -= i;
                i = 1;
                continue;
            } 
            i *= 2;
        }
        for (ll i = 2; i <= m; i *= 2) {
            cache[i] = cache[i/2] * cache[i/2];
        }
        for (auto e : exp) {
            ret *= cache[e];
        }
        
        return ret;
    }
};
