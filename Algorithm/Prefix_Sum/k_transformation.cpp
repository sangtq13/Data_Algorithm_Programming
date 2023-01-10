// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++


class Solution {
  public:
    vector<int> k_Transformation(int n, int m, int k, vector<vector<int> > grid, int q, vector<vector<int> > queries) {
        // calculate prefix sum array arr[i][j][l]
        // This is total numbers mod k equal to l 
        // in subgird with [0, 0] coordinates top left 
        // and [i, j] coordinates top right corner
        vector<int> ans;
        int pre[n][m][k];
        for (int l = 0; l < k; ++l) {
            pre[0][0][l] = 0;
        }
        
        pre[0][0][grid[0][0] % k] = 1;
        
        for (int i = 1; i < n; ++i) {
            for (int l = 0; l < k; ++l) {
                pre[i][0][l] = pre[i-1][0][l] + (grid[i][0] % k == l);
            }
        }
        
        for (int j = 1; j < m; ++j) {
            for (int l = 0; l < k; ++l) {
                pre[0][j][l] = pre[0][j-1][l] + (grid[0][j] % k == l);
            }
        }
        
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                for (int l = 0; l < k; ++l) {
                    pre[i][j][l] = pre[i-1][j][l] + pre[i][j-1][l] - pre[i-1][j-1][l] + (grid[i][j] % k == l);
                }
            }   
        }
        
        for (auto& qr : queries) {
            int count = 0;
            int t = qr[0];
            int val = qr[1];
            int lx = qr[2];
            int ly = qr[3];
            int rx = qr[4];
            int ry = qr[5];
            int l = val - t%k;
            if (l < 0) l += k;
            if (lx == 0 && ly == 0) {
                count = pre[rx][ry][l];
            }
            else if (lx == 0) {
                count = pre[rx][ry][l] - pre[rx][ly-1][l];
            }
            else if (ly == 0) {
                count = pre[rx][ry][l] - pre[lx-1][ry][l];
            }
            else {
                count = pre[rx][ry][l] - pre[lx-1][ry][l] - pre[rx][ly-1][l] + pre[lx-1][ly-1][l];
            }
            ans.push_back(count);
        }

        return ans;
    }
};

// { Driver Code Starts.


int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<vector<int> > grid(n, vector<int> (m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> grid[i][j];

        int q;
        cin >> q;
        vector<vector<int> > queries(q, vector<int> (6, 0));
        for (int i = 0; i < q; i++)
            for (int j = 0; j < 6; j++)
                cin >> queries[i][j];


        Solution ob;
        vector<int> ans = ob.k_Transformation(n, m, k, grid, q, queries);
        for (auto it: ans)
            cout << it << " ";
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
