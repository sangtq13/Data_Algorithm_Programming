class Solution(object):
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: O(n)
    # Space complexity: O(1)
    def findNonDuplicatedA(self, arr):
        result = 0
        for a in arr:
            result ^= a
        return result

    # Time complexity: O(n)
    # Space complexity: O(n)
    def findNonDuplicatedB(self, arr):
        d = {}
        for a in arr:
            d[a] = d.get(a,0) + 1
        for key, value in d.items():
            if value == 1:
                return key
        return -1

s = Solution()
arr = [1,2,3,4,3,2,1]
print(s.findNonDuplicatedA(arr))
print(s.findNonDuplicatedB(arr))
