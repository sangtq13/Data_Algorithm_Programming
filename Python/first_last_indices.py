class Solution(object):
    def __init(self):
        self.name = 'S->13'

    # Brute force
    # Time Complexity: O(n)
    # Space Complexity: O(1)
    def getRangeA(self, arr, target):
        first = -1
        last = -1
        check = False

        for index, value in enumerate(arr):
            if value == target and not check:
                first = index
                check = True
            if value != target and check:
                last = index - 1
                break
        return [first, last]
    # Using recursive binary search to find leftmost and rightmost target
    # Time complexity: O(log n)
    # Space complexity: O(log n) for adding stack
    def getRangeB(self, arr, target):
        first = self.binarySearch(arr, target, True)
        last = self.binarySearch(arr, target, False)

        return [first, last]

    # Using iterative binary search to find leftmost and rightmost target
    # Time complexity: O(log n)
    # Space complexity: O(1)
    def getRangeC(self, arr, target):
        first = self.binarySearchIterative(arr, target, True)
        last = self.binarySearchIterative(arr, target, False)

        return [first, last]

    def __binarySearchHelper(self, arr, left, right, target, leftMost=False):
        if left <= right:
            mid = (left+right) // 2
            if arr[mid] > target:
                return self.__binarySearchHelper(arr, left, mid-1, target, leftMost)
            elif arr[mid] == target:
                if leftMost:
                    if mid == 0 or arr[mid-1] != target:
                        return mid
                    else:
                        return self.__binarySearchHelper(arr, left, mid-1, target, leftMost)
                else:

                    if mid == len(arr)-1 or arr[mid+1] != target:
                        return mid
                    else:
                        return self.__binarySearchHelper(arr, mid+1, right, target, leftMost)
            else:
                return self.__binarySearchHelper(arr, mid+1, right, target, leftMost)

        return -1

    def binarySearch(self, arr, target, leftMost=False):
        return self.__binarySearchHelper(arr, 0, len(arr)-1, target, leftMost)

    def binarySearchIterative(self, arr, target, leftMost=False):
        left = 0
        right = len(arr) - 1
        while left <= right:
            mid = (left + right) // 2
            if arr[mid] > target:
                right = mid - 1
            elif arr[mid] == target:
                if leftMost:
                    if mid == 0 or arr[mid-1] != target:
                        return mid
                    else:
                        right = mid-1
                else:
                    if mid == len(arr)-1 or arr[mid+1] != target:
                        return mid
                    else:
                        left = mid+1
            else:
                left = mid+1
        return -1
    # Using binary seach for get range
    # Time complexity: O(log n)
    # Space complexity: O(1)
    # def getRangeBinarySearch(self):

arr = [1, 3, 3, 5, 7, 8, 9, 9, 9, 15]
s = Solution()
print(s.getRangeA(arr, 9))
print(s.getRangeB(arr, 9))
print(s.getRangeC(arr, 9))
