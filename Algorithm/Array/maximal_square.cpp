class Solution {
public:
    // Time complexity: O(row * col)
    // Space complexity: O(row * col)
    int maximalSquare(vector<vector<char>>& matrix) {   
        int max_square = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        int grid[row][col];
        for (int i = 0; i < row; ++i) {
            grid[i][0] = matrix[i][0] - '0';
            if (max_square < grid[i][0]) {
                max_square = grid[i][0];
            }
        }

        for (int i = 0; i < col; ++i) {
            grid[0][i] = matrix[0][i] - '0';
            if (max_square < grid[0][i]) {
                max_square = grid[0][i];
            }
        }

        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                if (matrix[i][j] == '1') {
                    grid[i][j] = min({grid[i-1][j], grid[i][j-1], grid[i-1][j-1]}) + 1;
                    int square = grid[i][j] * grid[i][j];
                    if (max_square < square) {
                        max_square = square;
                    }
                }
                else {
                    grid[i][j] = 0;
                }
                
            }
        }

        return max_square;
    }
};
