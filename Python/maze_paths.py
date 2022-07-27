class Solution():
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: O(n)
    # Space complexity: O(1)
    def MazePaths(self, grid):
        if grid[0][0] == 1:
            return 0
        row = len(grid)
        col = len(grid[0])
        for i in range(row):
            if grid[i][0] == 0:
                grid[i][0] = 1
            else:
                for j in range(i, row):
                    grid[j][0] = 0
                break

        for i in range(1, col):
            if grid[0][i] == 0:
                grid[0][i] = 1
            else:
                for j in range(i, col):
                    grid[0][j] = 0
                break

        for i in range(1, row):
            for j in range(1, col):
                if grid[i][j] == 1:
                    grid[i][j] = 0
                    continue
                else:
                    grid[i][j] = grid[i][j-1] + grid[i-1][j]
        return grid[-1][-1]

grid = [[0,0,0],[0,1,0],[0,0,0]]
grid = [[0,1],[0,0]]
grid =[[0,0], [1,1], [0,0]]
s = Solution()
print(s.MazePaths(grid))
