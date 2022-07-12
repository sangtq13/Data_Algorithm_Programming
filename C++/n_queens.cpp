class Solution {
public:    
    void solveNQueensHelper(vector<string> board, int n, set<int> col, set<int> asc_diag, set<int> dec_diag, int start_row, vector<vector<string>>& result) {
        if (start_row == n) {
            result.push_back(board);
        }
        for (int cur_col = 0; cur_col < n; ++cur_col) {
            if (col.find(cur_col) == col.end() && asc_diag.find(start_row + cur_col) == asc_diag.end() && dec_diag.find(start_row - cur_col) == dec_diag.end()) {
                col.emplace(cur_col);
                asc_diag.emplace(start_row + cur_col);
                dec_diag.emplace(start_row - cur_col);
                board[start_row][cur_col] = 'Q';

                solveNQueensHelper(board, n, col, asc_diag, dec_diag, start_row + 1, result);

                col.erase(cur_col);
                asc_diag.erase(start_row + cur_col);
                dec_diag.erase(start_row - cur_col);
                board[start_row][cur_col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        string s(n,'.');
        vector<string> board(n, s);
        set<int> col;
        set<int> asc_diag;
        set<int> dec_diag;
        vector<vector<string>> result;
        solveNQueensHelper(board, n, col, asc_diag, dec_diag, 0, result);
        return result;
    }
};
