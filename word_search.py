class Solution(object):
    def __init__(self):
        self.name = 'S->13'

    def getNeighbors(self, board, x, y):
        row = len(board)
        col = len(board[0])
        coordinators = [[0,1], [0,-1], [-1,0], [1,0]]
        neighbors = []
        for c in coordinators:
            nX = x + c[0]
            nY = y + c[1]
            if 0 <= nX < row and 0 <= nY < col:
                neighbors.append((nX,nY))

        return neighbors

    def __wordSearchHelper(self, board, word, x, y, index, visited):
        if index == len(word)-1 and board[x][y] == word[index]:
            return True
        if board[x][y] == word[index]:
            visited.append((x, y))
            for neighbor in self.getNeighbors(board, x, y):


    def wordSearchRecursive(self, board, word):
        row = len(board)
        col = len(board[0])
        lw = len(word)
        for i in range(row):
            for j in range(col):
                if self.__wordSearchHelper(board, word, i, j, 0, []):
                    return True

        return False

    def wordSearch(self, board, word):
        row = len(board)
        col = len(board[0])
        lw = len(word)
        for i in range(row):
            for j in range(col):
                stack = [(i, j, 0, [])]
                while stack:
                    x, y, index, visited = stack[-1]
                    visited.append((x, y))

                    if board[x][y] == word[index]:
                        if index == lw - 1:
                            return True
                        elif index < lw - 1:
                            for neighbor in self.getNeighbors(board, x, y):
                                if neighbor not in visited:
                                    stack.append((neighbor[0], neighbor[1], index+1, visited))

                    else:
                        visited.pop()

        return False

board = [["A","A","A","A","A","A"],
         ["A","A","A","A","A","A"],
         ["A","A","A","A","A","A"],
         ["A","A","A","A","A","A"],
         ["A","A","A","A","A","A"],
         ["A","A","A","A","A","A"]]
board = [["A","B","C","E"],
         ["S","F","E","S"],
         ["A","D","E","E"]]
# board = [["A","B","C","E"],
#          ["S","F","C","S"],
#          ["A","D","E","E"]]


# word = "AAAAAAAAAAAAAAB"
word = "ABCESEEEFS"
# word = "ABCB"

s = Solution()
# print(s.getNeighbors(board, 1, 0))
print(s.wordSearch(board, word))
