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

void Solution() {
    int n, m;
    cin >> n >> m;
    int grid[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
   
    vector<vector<int>> coords = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    auto Neighbors = [coords, n, m] (int x, int y) -> int {
        int neighbors = 0;
        for (auto c : coords) {
            if (0 <= x + c[0] && x + c[0] < n && 0 <= y + c[1] && y + c[1] < m) {
                neighbors++;
            }
        } 
        
        return neighbors;
    };

    bool check = false;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int neighbors = Neighbors(i, j);
            if (grid[i][j] > neighbors) {
                check = true;
                break;
            }
            else {
                grid[i][j] = neighbors;
            }
        }
    }

    if (check) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << grid[i][j] << " \n"[j == m-1];
            }
        }
    }
       
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        Solution();
    }
    return 0;
}
