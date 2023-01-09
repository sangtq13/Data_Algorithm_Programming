class Solution {
  public:
    vector<int> k_Transformation(int n, int m, int k, vector<vector<int> > grid, int q, vector<vector<int> > queries) {
        // calculate prefix sum array arr[i][j][l]
        // This is total numbers mod k equal to l 
        // in subgird with [0, 0] coordinates top left 
        // and [i, j] coordinates top right corner
        vector<int> ans;
        int pre[n][m][k] = {0};
        for (int i = 0; i < n; ++i) {
            pre[i][0][0] = 0;
        }
        for (int j = 0; j < m; ++j) {
            pre[0][j][0] = 0;
        }
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
                pre[i][j][0] = pre[i][j-1][0] + pre[i-1][j][0] - pre[i-1][j-1][0] + (grid[i][j] % k == 0);
            }
        }
        
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                for (int l = 1; l < k; ++l) {
                    pre[i][j][l] = pre[i-1][j][l] + pre[i][j-1][l] - pre[i-1][j-1][l] + (grid[i][j] % k == l);
                }
            }   
        }
        
        for (auto& qr : queries) {
            int t = qr[0];
            int val = qr[1];
            int lx = qr[2];
            int ly = qr[3];
            int rx = qr[4];
            int ry = qr[5];
            int l = val - t%k;
            if (l < 0) l += k;
            int count = pre[rx][ry][l] - pre[lx][ry][l] - pre[rx][ly][l] + pre[lx][ly][l];
            ans.push_back(count);
        }

        return ans;
    }
};
