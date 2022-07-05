class Solution(object):
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: O(n^2)
    # Space complexity: O(n)
    def queueReconstructionByHeight(self, arr):
        arr.sort(key=lambda x: -x[0])
        ret = []

        for a in arr:
            ret.insert(a[1], a)

        return ret
arr = [[7, 0], [4, 4], [7, 1], [5, 0], [6, 1], [5, 2]]
s = Solution()
print(s.queueReconstructionByHeight(arr))
