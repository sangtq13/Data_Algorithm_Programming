class Solution():
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: O(logn)
    # Space complexity: O(1)
    def SearchMatrix(self, matrix, target):
        rows = len(matrix)
        cols = len(matrix[0])
        left = 0
        right = rows * cols - 1
        while left <= right:
            mid = (left + right) // 2
            if matrix[int(mid / cols)][mid % cols] == target:
                return True
            elif matrix[int(mid / cols)][mid % cols] < target:
                left = mid + 1
            else:
                right = mid - 1

        return False

matrix = [[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60]]
matrix = [[1, 3]]
target = 3
target = 3
print(Solution().SearchMatrix(matrix, target))
# False
matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]]
target = 13
print(Solution().SearchMatrix(matrix, target))
# True
