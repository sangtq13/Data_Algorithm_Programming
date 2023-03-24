class Solution {
public:
    // Time complexity: O(n)
    // Space complexity: O(1)
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                // check row
                int r = i * 3 + j;
                set<char> s;
                cout << i << j << endl;
                for (int k = 0; k < 9; ++k) {
                    if (isdigit(board[r][k])) {
                        if (s.find(board[r][k]) != s.end()) {
                            return false;
                        }
                        s.insert(board[r][k]);
                    }
                }

                // check col
                s.clear();
                for (int k = 0; k < 9; ++k) {
                    if (isdigit(board[k][r])) {
                        if (s.find(board[k][r]) != s.end()) {
                            return false;
                        }
                        s.insert(board[k][r]);
                    }
                }

                // check square
                s.clear();
                int x = 3 * i;
                int y = 3 * j;
                for (int k = 0; k < 3; ++k) {
                    for (int h = 0; h < 3; ++h) {
                        if (isdigit(board[x+k][y+h])) {
                            if (s.find(board[x+k][y+h]) != s.end()) {
                                return false;
                            }
                            s.insert(board[x+k][y+h]);
                        }
                    }
                }

            }
        }

        return true;
    }
};
