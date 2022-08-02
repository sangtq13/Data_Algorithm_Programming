class Solution():
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: O(logn)
    # Space complexity: O(1)
    def NumberOneBits(self, n):
        count = 0
        while n >= 1:
            count += n & 1
            n >>=  1
        return count
n = 23
print(Solution().NumberOneBits(n))
