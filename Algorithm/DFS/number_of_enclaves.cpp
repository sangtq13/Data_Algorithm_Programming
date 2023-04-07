class Solution {
public:
    // Time complexity: O(m*n)
    // Space complexity: O(m*n) in worst case
    int numEnclaves(vector<vector<int>>& grid) {
        vector<pair<int, int>> directions {{0,1}, {0,-1}, {1,0}, {-1,0}};
        int r = grid.size();
        int c = grid[0].size();
        int ans = 0;

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j] == 1) {
                    stack<pair<int, int>> s;
                    s.push({i, j});
                    bool check = false;
                    int count = 0;
                    grid[i][j] = '.';
                    while (!s.empty()) {
                        pair<int, int> top = s.top();
                        s.pop();
                        int x = top.first;
                        int y = top.second;
                        count++;
                        if (x == 0 || y == 0 || x == r-1 || y == c-1) {
                            check = true;
                        }
                        for (auto d : directions) {
                            int x_new = x + d.first;
                            int y_new = y + d.second;
                            if (0 <= x_new && x_new < r && 
                                0 <= y_new && y_new < c && 
                                grid[x_new][y_new] == 1) {
                                s.push({x_new, y_new});
                                grid[x_new][y_new] = '.';
                            }
                        }
                    }
                    if (check == false) {
                        ans += count;
                    }
                }
            }
        }
        return ans;
    }
};
