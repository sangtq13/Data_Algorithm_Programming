from collections import OrderedDict
class Solution(object):
    def __init__(self):
        self.name = 'S->13'

    # For using normal sorting method, the complexity will be O(n log n) minimum.
    # So I don't mention this method in my implementation

    # Using hashmap
    # Timecomplexity: O(n)
    # Space complexity: O(n)
    def sortListThreeUniqueNumbersA(self, arr):
        d = OrderedDict()
        ret = []
        for m in arr:
            d[m] = d.get(m,0) + 1
        for key, count in d.items():
            ret += ([key] * count)
        return ret

    # Using swapping
    # Time complexity: O(n)
    # Space complexity: O(1)
    def sortListThreeUniqueNumbersB(self, arr):
        oneIndex = 0
        threeIndex = len(arr)-1
        index = 0

        while index <= threeIndex:
            if arr[index] == 1:
                arr[index], arr[oneIndex] = arr[oneIndex], arr[index]
                oneIndex += 1
                index += 1
            elif arr[index] == 2:
                index += 1
            elif arr[index] == 3:
                arr[index], arr[threeIndex] = arr[threeIndex], arr[index]
                threeIndex -= 1
        return arr

    def sortListThreadUniqueNumbersC(self, arr):
        n = len(arr)
        oneIndex = 0
        i = n-1
        threeIndex = n-1
        while i >= oneIndex:
            if arr[i] == 1:
                arr[i], arr[oneIndex] = arr[oneIndex], arr[i]
                oneIndex += 1
            if arr[i] == 3:
                arr[i], arr[threeIndex] = arr[threeIndex], arr[i]
                threeIndex -= 1
                i -= 1
            if arr[i] == 2:
                i -= 1
        return arr

arr = [1,2,3,1,3,2,1,1,3,2,1]
s = Solution()
# print(s.sortListThreeUniqueNumbersA(arr))
# print(s.sortListThreeUniqueNumbersB(arr))
print(s.sortListThreadUniqueNumbersC(arr))
