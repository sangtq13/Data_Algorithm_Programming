class Solution():
    # def __init__(self):

    def maxConnectedColors(self, grid):
        seen = {}
        maxCount = 0
        for i in range (len(grid)):
            for j in range(len(grid[0])):
                count = self.__traverse(grid, i, j, seen)
                maxCount = max(maxCount, count)

        return maxCount

    def __traverse(self, grid, x, y, seen):
        return self.__traverseHelper(grid, x, y, 0, seen)

    def __traverseHelper(self, grid, x, y, count, seen):
        key = "%s%s" % (x,y)
        if seen.get(key) != None:
            return 0
        seen[key] = True
        color = grid[x][y]
        total = 1
        neighbors = self.__getNeighbors(grid, x, y)
        for n in neighbors:
            neighborKey = "%s%s" % (n[0], n[1])
            if grid[n[0]][n[1]] == color and seen.get(neighborKey) == None:
                # total += self.__traverseHelper(grid, n[0], n[1], 1, seen)
                total += self.__traverseHelperIterative(grid, n[0], n[1], 1, seen)

        return total

    def __traverseHelperIterative(self, grid, x, y, count, seen):
        total = 1
        stack = []
        stack.append([x, y])
        color = grid[x][y]
        while stack:
            row, col = stack.pop()
            key = "%s%s" % (row, col)
            seen[key] = True
            neighbors = self.__getNeighbors(grid, row, col)
            for r, c in neighbors:
                neighborKey = "%s%s" % (r, c)
                if seen.get(neighborKey) == None and grid[r][c] == color:
                    total += 1
                    stack.append([r,c])

        return total

    def __getNeighbors(self, grid, x, y):
        neighbors = []
        coords = [
            [0, -1],
            [-1, 0],
            [0, 1],
            [1, 0]
        ]
        for c in coords:
            coordX = x + c[0]
            coordY = y + c[1]
            if (0 <= coordX < len(grid) and (0 <= coordY < len(grid[0]))):
                neighbors.append([coordX, coordY])

        return neighbors

grid = [
['r', 'g', 'b'],
['r', 'r', 'r'],
['g', 'g', 'r']
]
s = Solution()
print(s.maxConnectedColors(grid))