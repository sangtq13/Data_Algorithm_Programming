class Solution {
public:
    // Time complexity: O(m*n)
    // Space complexity: O(m*n)
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool visited[m][n];
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0 && visited[i][j] == false) {
                    visited[i][j] = true;
                    for (int x = 0; x < n; ++x) {
                        if (matrix[i][x] != 0) {
                            matrix[i][x] = 0;
                            visited[i][x] = true;
                        }
                    }
                    for (int x = 0; x < m; ++x) {
                        if (matrix[x][j] != 0) {
                            matrix[x][j] = 0;
                            visited[x][j] = true;
                        }
                    }
                }
            }
        }
    }
};
