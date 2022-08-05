class Solution():
    def __init__(self):
        self.name = 'S->13'

    def OptimalJump(self, nums):
        n = len(nums)
        cur = 0
        jumps = 0
        far = 0
        for i in range(n):
            far = max(far, i+nums[i])
            if i == cur and i != n-1:
                cur = far
                jumps += 1
        return jumps

    # DP method
    # Time complexity: O(n^2)
    # Space complexity: O(n)
    def JumpGame(self, nums):
        n = len(nums)
        dp = [n] * n
        dp[0] = 0
        for i in range(n):
            for j in range(i+1, min(i+nums[i]+1, n)):
                dp[j] = min(dp[i]+1, dp[j])

        return dp[-1]

    # Time complexity: O(n)
    # Space complexity: O(1)
    def canJump(self, nums):
        n = len(nums)
        far = 0
        for i in range(n):
            if far < i:
                return False
            far = max(far, i + nums[i])
            if far >= n - 1:
                return True
        return False

nums = [3, 2, 5, 1, 1, 9, 3, 4]
nums = [3,2,1,0,4]
print(Solution().JumpGame(nums))
print(Solution().OptimalJump(nums))
print(Solution().canJump(nums))
