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
  int n, q;
  cin >> n >> q;
  int arr[n];
  for (int i = 0; i < n; ++i) {
    int num;
    cin >> num;
    arr[i] = num;
  }

  // Time complexity for query: O(1)
  // Space complexity: O(n^2)
  ll dp[n][n][2];
	for (int i = 0; i < n-1; ++i) {
		dp[i][i+1][0] = abs(arr[i+1] - arr[i]);
    dp[i][i+1][1] = arr[i] + arr[i+1];
	}

	for (int i = 0; i < n-2; ++i) {
		for (int j = i+2; j < n; ++j) {
			ll diff = arr[j] - arr[j-1];
			dp[i][j][1] = dp[i][j-1][1] + arr[j];
			if ((diff % dp[i][j-1][0]) == 0) {
				dp[i][j][0] = dp[i][j-1][0];
			}
			else {
				ll value = abs((j-i) * arr[j] - dp[i][j-1][1]);
				for (ll k = min(static_cast<ll>(sqrt(value)), k-1); k >= 1; --k) {
					if (value % k == 0) {
						dp[i][j][0] = k;
						break;
					}
				}
			}
		}
	}

	for (int i = 0; i < q; ++i) {
		int l, r;
		cin >> l >> r;
		cout << dp[l-1][r-1][0] << endl;
	}

  return 0;
}

// Input:
// 3 3 
// 2 3 5 
// 1 2 
// 2 3
// 1 3

// Output:
// 1
// 2
// 1
