class Solution(object):
    def __init__(self):
        self.name = 'S->13'

    def __numberOfIslandsHelper(self, grid, i, j, rows, cols):
        direction = [(0,1), (1,0), (-1,0), (0,-1)]
        grid[i][j] = '*'
        for d in direction:
            x = i + d[0]
            y = j + d[1]
            if 0 <= x < rows and 0 <= y < cols and grid[x][y] == 1:
                self.__numberOfIslandsHelper(grid, x, y, rows, cols)

    # Time complexity: O(m*n)
    # Space complexity: O(m*n) for stack of recursive method
    def numberOfIslandsRecursive(self, grid):
        rows = len(grid)
        cols = len(grid[0])
        numIslands = 0
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1:
                    self.__numberOfIslandsHelper(grid, i, j, rows, cols)
                    numIslands += 1

        return numIslands

    # Time complexity: O(m*n)
    # Space complexity: O(m*n) for using stack
    def numberOfIslands(self, grid):
        direction = [(0, 1), (1, 0), (-1, 0), (0, -1)]
        rows = len(grid)
        cols = len(grid[0])
        numIslands = 0
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1:
                    stack = [(i,j)]
                    while stack:
                        x, y = stack.pop()
                        grid[x][y] = '*'
                        for d in direction:
                            nX = x + d[0]
                            nY = y + d[1]
                            if 0 <= nX < rows and 0 <= nY <cols and grid[nX][nY] == 1:
                                stack.append((nX, nY))

                    numIslands += 1
        return numIslands

grid = [[1, 1, 0, 0, 0],
        [0, 1, 0, 0, 1],
        [1, 0, 0, 1, 1],
        [0, 0, 0, 0, 0]]
s = Solution()
print(s.numberOfIslandsRecursive(grid))
print(s.numberOfIslands(grid))
