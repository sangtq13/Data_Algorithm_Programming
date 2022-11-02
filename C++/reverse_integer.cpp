#define ll long long
class Solution {
public:
    // Time compelxity: O(n)
    // Space complexity: O(1)
    int reverse(int x) {
        int sign = 1;
        int n = 0;
        ll num = x;
        if (x < 0) {
            sign = -1;
            num *= (-1);
        }
        while (num > 0) {
            if (n > INT_MAX / 10) return 0;
            n = n * 10 + num % 10;
            num /= 10;
        }
        return sign * n;
    }
};
