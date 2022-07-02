vector<vector<int>> directions {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
class Solution {
public:
    void maxAreaHelper(vector<vector<int>>& grid, int x, int y, int rows, int cols, int& currentLen) {
        currentLen += 1;
        grid[x][y] = 0;
        for (auto& d: directions) {
            int nx = x + d[0];
            int ny = y + d[1];
            if (0 <= nx && nx < rows && 0 <= ny && ny < cols && grid[nx][ny] == 1) {
                this->maxAreaHelper(grid, nx, ny, rows, cols, currentLen);
            }
        }
    }
        
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxLen = 0;
        int currentLen = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    this->maxAreaHelper(grid, i, j, rows, cols, currentLen);
                    maxLen = max(maxLen, currentLen);
                    currentLen = 0;
                }
            }
        }
        return maxLen;
    }
};
