#include <bits/stdc++.h>

using namespace std;
/*
 * Complete the 'substrings' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

const int MOD = 1e9+7;

// Time complexity: O(n)
// Space complexity: O(n)
int substrings(string s) {
    int n = s.size();
    int start = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            start++;
        }
        else {
            break;
        }
    }
    if (start >= n) return 0;
    long long dp[n - start+1];
    dp[0] = 0;
    dp[1] = s[start] - '0';
    
    for (int i = start+1; i < n; ++i) {
        dp[i-start+1] = (11 * dp[i-start] - 10 * dp[i-start-1] + (s[i] - '0') * (i - start + 1)) % MOD;
        if (dp[i-start+1] < 0) dp[i-start+1] += MOD;
    }
    
    return dp[n-start];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n;
    getline(cin, n);

    int result = substrings(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
