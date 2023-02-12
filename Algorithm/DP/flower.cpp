#include<bits/stdc++.h>
#define ll                    long long int
#define pb                    push_back
#define F                     first
#define S                     second
#define mp                    make_pair
#define MOD                   1000000007
#define vi                    vector<int>
#define vll                   vector<ll>
#define pll                   pair<ll,ll>
#define pii                   pair<int,int>
#define mid(s,e)              (s+(e-s)/2)
#define eb                    emplace_back
#define ull                   unsigned long long
#define bug(x)				  cout<<"  [ "#x<<" = "<<x<<" ]"<<endl;
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n, k;
    cin >> n >> k;
    ll arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    // Time complexity: O(n)
    // Space complexity: O(n)
    ll dp[n][4];
    dp[0][0] = arr[0];
    dp[0][1] = 0;
    dp[0][2] = 1;
    dp[0][3] = arr[0];
    for (int i = 1; i < n; ++i) {
        if (dp[i-1][2] < k-1) {
            dp[i][0] = dp[i-1][0] + arr[i];
            dp[i][1] = (arr[i] < arr[dp[i-1][1]] || dp[i-1][1] == -1) ? i : dp[i-1][1];
            dp[i][2] = dp[i-1][2] + 1;
            dp[i][3] = dp[i-1][3] + arr[i];
        }
        else {
            if (arr[i] < arr[dp[i-1][1]]) {
                dp[i][0] = dp[i-1][0];
                dp[i][1] = -1;
                dp[i][2] = 0;
                dp[i][3] = 0;
            }
            else {
                dp[i][0] = dp[i-1][3] - arr[dp[i-1][1]] + arr[i];
                if (i-k >= 0) dp[i][0] += dp[i-k][0];
                dp[i][1] = dp[i-1][1] + 1;
                dp[i][2] = i - dp[i-1][1];
                dp[i][3] = 0;
                for (int j = dp[i][1]; j <= i; ++j) {
                    if (arr[j] < arr[dp[i][1]]) {
                        dp[i][1] = j;
                    }
                    dp[i][3] += arr[j];
                }
            }
        }
    }

    std::cout << dp[n-1][0] << std::endl;

    return 0;
}
