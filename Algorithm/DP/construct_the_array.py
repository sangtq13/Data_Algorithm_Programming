MOD = 10**9 + 7
class Solution():
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: O(n)
    # Space complexity: O(n)
    def ConstructArray(self, n, k, x):
        dp = [0] * n
        path = [1] * n
        if x == 1: dp[0] == 1

        for i in range(1, n):
            path[i] = (path[i-1] * (k-1)) % MOD
            dp[i] = (path[i-1] - dp[i-1] + MOD) % MOD

        return dp[n-1]

n = 5
k = 3
x = 2
print(Solution().ConstructArray(n, k, x))

