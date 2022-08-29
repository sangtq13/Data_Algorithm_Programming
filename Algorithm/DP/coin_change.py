class Solution():
    def __init__(self):
        self.name = 'S->13'

    # Recursive method
    # Time complexity: O(2^target)
    # Space complexity: O(target)
    def __CoinChangeHelper(self, coins, n, target):
        if target == 0:
            return 1
        if target < 0:
            return 0
        if n <= 0:
            return 0
        x = self.__CoinChangeHelper(coins, n, target - coins[n-1])
        y = self.__CoinChangeHelper(coins, n-1, target)
        return x + y

    def CoinChangeRecursive(self, coins, target):
        n = len(coins)
        return self.__CoinChangeHelper(coins, n, target)

    # Time complexity: O(m*n)
    # Space complexity: O(m*n)
    def CoinChangeDP(self, coins, target):
        n = len(coins)
        dp = [[0] * (target+1) for _ in range(n)]
        for i in range(n):
            dp[i][0] = 1
        for i in range(n):
            for j in range(1, target + 1):
                if i >= 1:
                    dp[i][j] += dp[i-1][j]
                if j - coins[i] >= 0:
                    dp[i][j] += dp[i][j-coins[i]]

        return dp[n-1][target]

coins = [8, 1, 2, 3]
coins = [2, 3, 5, 6]
target = 40
s = Solution()
print(s.CoinChangeRecursive(coins, target))
print(s.CoinChangeDP(coins, target))
