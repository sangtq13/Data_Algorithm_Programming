class Solution(object):
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: O(n)
    # Space complexity: O(1)
    def maximumSubarray(self, nums):
        sum = 0
        maxSum = float('-inf')
        for n in nums:
            sum += n
            maxSum = max(maxSum, sum)
            if sum < 0:
                sum = 0
        return maxSum

nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
print(Solution().maximumSubarray(nums))
