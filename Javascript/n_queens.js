/**
 * @param {number} n
 * @return {string[][]}
 */
var SolveNqueensHelper = (board, n, col, asc_dig, dec_dig, queens_pos, result) => {
    var cur_row = queens_pos.length
    for (var cur_col = 0; cur_col < n; ++cur_col) {
        var check = false
        if (!col.has(cur_col) && !asc_dig.has(cur_row + cur_col) && !dec_dig.has(cur_row - cur_col)) {
            check = true
            queens_pos.push([cur_row, cur_col])
            col.add(cur_col)
            asc_dig.add(cur_row + cur_col)
            dec_dig.add(cur_row - cur_col)
            board[cur_row][cur_col] = 'Q'
            if (queens_pos.length === n) {
                var ret = []
                for (i in board) {
                    ret.push(board[i].join(''))
                }
                result.push(ret)
            }
            else {
                SolveNqueensHelper(board, n, col, asc_dig, dec_dig, queens_pos, result)
            }
        }
        if (check) {
            var top = queens_pos.pop()
            col.delete(top[1])
            asc_dig.delete(top[0] + top[1])
            dec_dig.delete(top[0] - top[1])
            board[top[0]][top[1]] = '.'
        }
    }
}

// Time complexity: O(nˆn)
// Space complexity: O(n)
var solveNQueens = function(n) {
    var board = [...Array(n)].map(x=>Array(n).fill('.'))
    var col = new Set()
    var asc_dig = new Set()
    var dec_dig = new Set()
    var result = []
    SolveNqueensHelper(board, n, col, asc_dig, dec_dig, [], result)
    return result
};
