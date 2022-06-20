RIGHT = 0
UP = 1
LEFT = 2
DOWN = 3
class Solution(object):
    def __init__(self):
        self.name = 'S->13'

    def __nextPosition(self, currentPos, currentDir):
        if currentDir == RIGHT:
            return (currentPos[0], currentPos[1]+1)
        if currentDir == LEFT:
            return (currentPos[0], currentPos[1]-1)
        if currentDir == UP:
            return (currentPos[0]-1, currentPos[1])
        if currentDir == DOWN:
            return (currentPos[0]+1, currentPos[1])

    def __validPosition(self, matrix, currentPos):
        row = len(matrix)
        col = len(matrix[0])
        if 0 <= currentPos[0] < row and 0 <= currentPos[1] < col and matrix[currentPos[0]][currentPos[1]] != '*':
            return True
        return False

    def __next_direction(self, direction):
        return {
            RIGHT: DOWN,
            DOWN: LEFT,
            LEFT: UP,
            UP: RIGHT
        }[direction]

    def spiralTraversal(self, matrix):
        row = len(matrix)
        col = len(matrix[0])
        result = [[0] * col for _ in range(row)]
        current_direction = RIGHT
        current_position = (0, 0)
        i = 0
        j = 0
        remain = row*col
        while remain:
            remain -= 1
            result[i][j] = matrix[current_position[0]][current_position[1]]
            matrix[current_position[0]][current_position[1]] = '*'
            nextPos = self.__nextPosition(current_position, current_direction)
            if not self.__validPosition(matrix, nextPos):
                current_direction = self.__next_direction(current_direction)
                current_position = self.__nextPosition(current_position, current_direction)
            else:
                current_position = nextPos

            j += 1
            if j == col:
                j = 0
                i += 1
        return result

matrix = [[1,2,3],[4,5,6],[7,8,9]]
s = Solution()
print(s.spiralTraversal(matrix))
