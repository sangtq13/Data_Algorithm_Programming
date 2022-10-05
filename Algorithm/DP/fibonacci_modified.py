class Solution:
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: O(n)
    # Space complexity: O(n)
    def FibonacciModified(self, t1, t2, n):
        # Write your code here
        dp = [0 for _ in range(n + 1)]
        dp[1] = t1
        dp[2] = t2
        for i in range(3, n + 1):
            dp[i] = dp[i - 1] * dp[i - 1] + dp[i - 2];

        return dp[n]

t1 = 0
t2 = 1
print(Solution().FibonacciModified(t1, t2, 20))
