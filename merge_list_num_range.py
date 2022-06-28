class Solution(object):
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: O(n)
    # Space complexity: O(n)
    def findRange(self, nums):
        l = len(nums)
        if l == 0:
            return []
        if l == 1:
            return [str(nums[0])]
        start = nums[0]
        result = []
        nums.append(nums[-1] + 2)
        for i in range(1, l + 1):
            if nums[i] - nums[i - 1] > 1:
                if nums[i - 1] == start:
                    result.append(str(start))
                else:
                    result.append(str(start) + '->' + str(nums[i - 1]))
                start = nums[i]
        return result
nums = [0, 1, 2, 5, 7, 8, 9, 9, 10, 11, 15]
print(Solution().findRange(nums))
