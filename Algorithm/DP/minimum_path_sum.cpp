class Solution {
public:
    // Time complexity: O(m*n)
    // Space complexity: O(1)
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for (int i = 1; i < n; ++i) grid[0][i] = grid[0][i-1] + grid[0][i];
        for (int i = 1; i < m; ++i) grid[i][0] = grid[i-1][0] + grid[i][0];
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                grid[i][j] = min(grid[i-1][j], grid[i][j-1]) + grid[i][j];
            }
        }

        return grid[m-1][n-1];
    }
};
