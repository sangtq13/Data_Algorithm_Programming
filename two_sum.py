from collections import defaultdict
class Solution(object):
    def __init__(self):
        self.name = 'S->13'

    # Brute force
    # Time complexity: O(n^2)
    # Space complexity: O(1)
    def twoSumA(self, arr, target):
        n = len(arr)
        for i in range(n):
            for j in range(i+1, n):
                if arr[i] + arr[j] == target:
                    return [i, j]
        return []

    # Using hash map
    # Time complexity: O(n)
    # Space complexity: O(n)
    def twoSumB(self, arr, target):
        n = len(arr)
        d = defaultdict()
        for index, a in enumerate(arr):
            diff = target - a
            if diff in d:
                return [d[diff], index]
            d[a] = index
        return []
    # Partition for quick sort
    def __partition(self, arr, low, high):
        mid = (low+high)//2
        pivot = arr[mid]
        i = low
        j = high
        while i < j:
            while arr[i] < pivot:
                i += 1
            while arr[j] > pivot:
                j -= 1
            arr[i], arr[j] = arr[j], arr[i]
        if i>=j:
            return j
        return i+1

    def __quickSort(self, arr, low, high):
        if low < high:
            pi = self.__partition(arr, low, high)
            self.__quickSort(arr, low, pi-1)
            self.__quickSort(arr, pi+1, high)

    # Using quick sort
    # Return a pair that sum equals target
    def twoSumC(self, arr, target):
        i = 0
        j = len(arr)-1
        self.__quickSort(arr, i, j)
        while i < j:
            if arr[i] + arr[j] > target:
                j -= 1
            elif arr[i] + arr[j] < target:
                i += 1
            else:
                return [arr[i], arr[j]]
        return []


s = Solution()
arr = [2, 7, 11, 15, 9, 5, 6, 12, 14]
print(s.twoSumA(arr, 18))
print(s.twoSumB(arr, 18))
print(s.twoSumC(arr, 18))
# s.quickSort(arr, 0, len(arr)-1)
# print(arr)
