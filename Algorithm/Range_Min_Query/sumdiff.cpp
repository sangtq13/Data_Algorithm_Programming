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
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; ++i) {
    int num;
    cin >> num;
    arr[i] = num;
  }

  // Time complexity: O(n^2)
  // Space complexity: O(n^2)
  ll dp[n][n][2];
  ll sum = 0;
	for (int i = 0; i < n-1; ++i) {
		dp[i][i+1][0] = max(arr[i], arr[i+1]);
    dp[i][i+1][1] = min(arr[i], arr[i+1]);
    sum += (dp[i][i+1][0] - dp[i][i+1][1]);
	}

	for (int i = 0; i < n-2; ++i) {
		for (int j = i+2; j < n; ++j) {
			if (arr[j] > dp[i][j-1][0]) {
				dp[i][j][0] = arr[j];
				dp[i][j][1] = dp[i][j-1][1];
			}
			else if (arr[j] < dp[i][j-1][1]) {
				dp[i][j][0] = dp[i][j-1][0];
				dp[i][j][1] = arr[j];
			}
			else {
				dp[i][j][0] = dp[i][j-1][0];
				dp[i][j][1] = dp[i][j-1][1];
			}
			sum += (dp[i][j][0] - dp[i][j][1]);
		}
	}

	cout << sum << endl;

  return 0;
}

// Input:
// 4
// 3
// 1
// 7
// 2

// Output: 
// 31
