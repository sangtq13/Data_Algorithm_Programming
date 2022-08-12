class Solution():
    def __init__(self):
        self.name = 'S->13'

    def __LISHelper(self, nums, n, max_len):
        if n == 1:
            return 1
        max_ending_here = 1
        for i in range(n-1):
            res = self.__LISHelper(nums, i + 1, max_len)
            if nums[i] < nums[n-1] and res + 1 > max_ending_here:
                max_ending_here = res + 1
        if max_ending_here > max_len[0]:
            max_len[0] = max_ending_here
        return max_ending_here

    # Time complexity: exponential
    # Space complexity: O(1)
    def LISRecursive(self, nums):
        max_len = [1]
        self.__LISHelper(nums, len(nums), max_len)
        return max_len[0]

    # Time complexity: O(nˆ2)
    # Space complexity: O(n)
    def LongestIncreaseSubsequence(self, nums):
        n = len(nums)
        dp = [1] * n
        max_len = 1
        for i in range(1, n):
            for j in range(i):
                if nums[j] < nums[i] and dp[j] + 1 > dp[i]:
                    dp[i] = dp[j] + 1
            if dp[i] > max_len:
                max_len = dp[i]
        return max_len

nums = [10,9,2,5,3,7,101,18]
s = Solution()
print(s.LongestIncreaseSubsequence(nums))
print(s.LISRecursive(nums))
