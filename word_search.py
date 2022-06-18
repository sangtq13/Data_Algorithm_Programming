class Solution(object):
    def __init__(self):
        self.name = 'S->13'

    def wordSearchRecursive(self, board, word):
        row = len(board)
        col = len(board[0])

        for i in range(row):
            for j in range(col):
                if self.__wordSearchHelper(board, word, i, j, 0):
                    return True
        return False

    # Backtracking method
    # Time complexity: O(m*n) with m, n is row and col of matrix
    # Space complexity: O(m*n) for checking visited and for stack of recursive function
    def __wordSearchHelper(self, board, word, x, y, start=0):
        row = len(board)
        col = len(board[0])
        lw = len(word)-1
        direction = [[0, 1], [0, -1], [-1, 0], [1, 0]]
        if board[x][y] != word[start]:
            return False
        if start == lw:
            return True
        board[x][y] = True
        for c in direction:
            nX = x + c[0]
            nY = y + c[1]
            if 0 <= nX < row and 0 <= nY < col and board[nX][nY] != True:
                ret = self.__wordSearchHelper(board, word, nX, nY, start+1)
                if ret:
                    return True
        board[x][y] = word[start]
        return False

    # Using stack method
    # Time complexity: O(m*n)
    def wordSearchIterative(self, board, word):
        row = len(board)
        col = len(board[0])
        lw = len(word)
        direction = [[0, 1], [0, -1], [-1, 0], [1, 0]]
        for i in range(row):
            for j in range(col):
                stack = [(i, j, 0, [[0]*col for _ in range(row)])]
                while stack:
                    x, y, start, seen= stack.pop()
                    if board[x][y] == word[start]:
                        if start == lw-1:
                            return True
                        for c in direction:
                            nX = x + c[0]
                            nY = y + c[1]
                            if 0 <= nX < row and 0 <= nY < col and seen[nX][nY] != 1:
                                newVisited = [x[:] for x in seen]
                                newVisited[x][y] = 1
                                stack.append((nX, nY, start+1, newVisited))
        return False

# board = [["A","A","A","A","A","A"],
#          ["A","A","A","A","A","A"],
#          ["A","A","A","A","A","A"],
#          ["A","A","A","A","A","A"],
#          ["A","A","A","A","A","A"],
#          ["A","A","A","A","A","A"]]
# word = "AAAAAAAAAAAAAAB"
board = [["A","B","C","E"],
         ["S","F","E","S"],
         ["A","D","E","E"]]
word = "ABCESEEEFS"
#
# board = [["A","B","C","E"],
#          ["S","F","E","S"],
#          ["A","D","E","E"]]
# word = "ABCB"
#
# board = [["C","A","A"],
#          ["A","A","A"],
#          ["B","C","D"]]
# word = 'AAB'

# board = [["A","B","C","E"],
#          ["S","F","C","S"],
#          ["A","D","E","E"]]
# word = "ABCCED"

s = Solution()
# print(s.wordSearchRecursive(board, word))
print(s.wordSearchIterative(board, word))
