class Solution {
public:
    int count(int n) {
        int count = 0;
        int i = 1;
        while (i <= n) {
            if (i == n) {
                count++;
                break;
            }
            if (i * 2 > n) {
                count++;
                n = min(n-i, 2*i - n);
                i = 1;
            }
            else {
                i *= 2;
            }
        }
        return count;
    }
    
    // Time complexity: O(logn)
    // Space complexity: O(1)
    int minOperations(int n) {
        int i = 1;
        while (i <= n) {
            if (i * 2 > n) break;
            i *= 2;
        }
        
        int num1 = n - i;
        int num2 = 2 * i - n;
        int c1 = count(num1) + 1;
        int c2 = count(num2) + 1;
        return min(c1, c2);
    }
};
