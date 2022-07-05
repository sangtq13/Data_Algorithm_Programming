class Solution(object):
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: O(n)
    # Space complexity: O(n) for using stack
    def climStairsRecursive(self, n):
        if n == 1 or n == 2:
            return n
        return self.climStairsRecursive(n-1) + self.climStairsRecursive(n-2)

    # Time complexity: O(n)
    # Space complexity: O(1)
    def climbStairsIterative(self, n):
        if n == 1 or n == 2:
            return n
        pre = 1
        cur = 2
        for i in range(3, n + 1):
            tmp = cur
            cur = pre + cur
            pre = tmp

        return cur

n = 4
print(Solution().climbStairsIterative(n))
