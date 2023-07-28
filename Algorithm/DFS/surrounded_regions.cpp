class Solution {
public:
    // Time complexity: O(m*n)
    // Space complexity: O(m+n)
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<pair<int, int>> coords = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') q.push({i, 0});
            if (board[i][n-1] == 'O') q.push({i, n-1});
        }
        for (int i = 0; i < n; ++i) {
            if (board[0][i] == 'O') q.push({0, i});
            if (board[m-1][i] == 'O') q.push({m-1, i});
        }
                    
        while (!q.empty()) {
            pair<int, int> node = q.front();
            q.pop();
            if (board[node.first][node.second] == '#') continue;
            board[node.first][node.second] = '#';
            for (auto& coord : coords) {
                int x = coord.first + node.first;
                int y = coord.second + node.second;
                if (0 <= x && x < m && 0 <= y && y < n && board[x][y] == 'O') {
                    q.push({x, y});
                }
            }
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
