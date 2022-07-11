class Solution(object):
    def __SolveQueensHelper(self, board, n, col, asc_diag, dec_diag, queens_pos, result):
        current_row = len(queens_pos)
        for current_col in range(n):
            check = False
            if col[current_col] and asc_diag[current_row + current_col] and dec_diag[current_row - current_col]:
                check = True
                queens_pos.append((current_row, current_col))
                board[current_row][current_col] = 'Q'
                col[current_col] = False
                asc_diag[current_row + current_col] = False
                dec_diag[current_row - current_col] = False
                if len(queens_pos) == n:
                    ret = [''.join(a) for a in board]
                    result.append(ret)
                else:
                    self.__SolveQueensHelper(board, n, col, asc_diag, dec_diag, queens_pos, result)
            if check:
                topx, topy = queens_pos.pop()
                col[topy] = True
                asc_diag[topx + topy] = True
                dec_diag[topx - topy] = True
                board[current_row][current_col] = '.'
    
    // Time complexity: O(n!)
    // Space complexity: O(n)
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        board = [['.'] * n for _ in range(n)]
        col = [True] * n
        asc_diag = [True] * (2*n-1)
        dec_diag = [True] * (2*n-1)
        result = []
        self.__SolveQueensHelper(board, n, col, asc_diag, dec_diag, [], result)

        return result
        
