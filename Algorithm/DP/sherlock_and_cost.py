class Solution():
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: O(n)
    # Space complexity: O(n)
    # 0 for choose 1, 1 for choose B[i]
    def SherlockAndCost(self, nums):
        n = len(nums)
        dp = [[0] * 2 for _ in range(n)]
        for i in range(1, n):
            dp[i][0] = max(dp[i-1][0] + abs(1 - 1), dp[i-1][1] + abs(1 - nums[i-1]))
            dp[i][1] = max(dp[i-1][0] + abs(nums[i] - 1), dp[i-1][1] + abs(nums[i] - nums[i-1]))
        
        return max(dp[n - 1][0], dp[n - 1][1])
      
nums = [1,2,3,4]
print(Solution().SherlockAndCost(nums))
