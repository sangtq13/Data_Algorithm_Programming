class Solution {
public:
    string longestPalindrome(string s) {
        int m = 1;
        int n = s.size();
        int dp[n][n+1];
        for (int i = 0; i < n; ++i) {
            dp[i][1] = 1;
            dp[i][0] = 1;
        }
        
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j <= n-i; ++j) {
                if (dp[j+1][i-2] && s[j+i-1] == s[j]) {
                    dp[j][i] = 1;
                    if (i > m) m = i;
                }
                else {
                    dp[j][i] = 0;
                }
            }
        }
        for (int i = 0; i < n-m+1; ++i) {
            if (dp[i][m] == 1){
                return s.substr(i, m);
            }
        }
    }
};
