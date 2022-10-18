class Solution():
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: O(n)
    # Space complexity: O(1)
    def MaxSubsequenceSubArray(self, nums):
        ret = []
        max_subarray = -1e4
        max_subsequence = 0
        max_num = -1e4
        sum = 0
        for i in range(len(nums)):
            sum = max(nums[i], sum + nums[i])
            max_subarray = max(sum, max_subarray)
            if nums[i] > 0: max_subsequence += nums[i]
            if nums[i] > max_num: max_num = nums[i]
        ret.append(max_subarray)
        if max_subsequence > 0:
            ret.append(max_subsequence)
        else:
            ret.append(max_num)
        return ret

nums = [2, -1, 2, 3, 4, -5]
print(Solution().MaxSubsequenceSubArray(nums))
