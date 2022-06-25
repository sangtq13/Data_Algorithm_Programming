class Solution():
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: O(n)
    # Space complexity: O(n)
    def firstMissingPositiveIntegerA(self, nums):
        s = set(nums)
        while first in s:
            first += 1
        return first

    def firstMissingPositiveIntegerB(self, nums):
        l = len(nums)
        for i in range (l):
            while nums[i] <= l and nums[i] > 0 and nums[i] != nums[nums[i]-1]:
                tmp = nums[i]-1
                nums[i], nums[tmp] = nums[tmp], nums[i]
        for i, n in enumerate(nums):
            if n != i + 1:
                return i + 1

s = Solution()
nums = [2, 1, 7, 3, -1, 4]
print(s.firstMissingPositiveIntegerB(nums))
