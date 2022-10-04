MOD = 1e9 + 7
class Solution():
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: O(n)
    # Space complexity: O(n)
    def SumSubstrings(self, s):
        n = len(s)
        start = 0
        for i in range(n):
            if s[i] == '0':
                start += 1
            else:
                break
        if start >= n: return 0
        dp = [0 for _ in range(n-start+1)]
        dp[1] = int(s[start])
        for i in range(start+1, n):
            dp[i - start + 1] = (11 * dp[i - start] - 10 * dp[i - start - 1] + int(s[i]) * (i - start + 1) + MOD) % MOD
        return dp[-1]
s = '002345'
print(Solution().SumSubstrings(s))
