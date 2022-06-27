class Solution(object):
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: O(n)
    # Space complexity: O(1)
    def minSubArrayLen(self, nums, target):
        start = 0
        sum = 0
        minLen = float('inf')

        for i, v in enumerate(nums):
            sum += v
            while sum >= target:
                minLen = min(minLen, i-start+1)
                sum -= nums[start]
                start += 1
        return minLen

nums = [2, 3, 1, 2, 4, 3]
target = 7
s = Solution()
print(s.minSubArrayLen(nums, target))
