MOD = 1e9 + 7
MAX_XOR = (1 << 13) -1
class Solution:
    def __init__(self):
        self.name = 'S->13'
    # For range of num: 3500 - 4500
    # Time complexity: O(1001 * 8192)
    # Space complexity: O(2 * 8192)
    def PrimeXor(self, nums):
        primes = [True for _ in range(MAX_XOR + 1)]
        p = 2
        while p * p <= MAX_XOR:
            if primes[p] == True:
                for i in range(p * p, MAX_XOR + 1, p):
                    primes[i] = False
            p += 1
        count = [0 for _ in range(1001)]
        for num in nums:
            count[num - 3500] += 1
        dp = [[0] * (MAX_XOR + 1) for _ in range(2)]
        dp[0][0] = count[0] // 2 + 1
        dp[0][3500] = (count[0] + 1) // 2
        flag = 1
        for i in range(1, 1001):
            for j in range(MAX_XOR + 1):
                dp[flag][j] = dp[1 - flag][j] * (count[i] // 2 + 1) + dp[1 - flag][j ^ (i + 3500)] * ((count[i] + 1) // 2)
                dp[flag][j] %= MOD
            flag = 1 - flag

        ans = 0
        for i in range(2, 8192):
            if primes[i] == True:
                ans += dp[1 - flag][i]
                ans %= MOD

        return int(ans)


nums = [3511, 3671, 4153]
print(Solution().PrimeXor(nums))
