class Solution(object):
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: O(n)
    # Space complexity: O(1)
    def nonDecreaseArray(self, nums):
        n = len(nums)
        count = 0
        for i in range(n - 1):
            if nums[i] > nums[i + 1]:
                print(count, i)
                count += 1
                if count > 1:
                    return False
                if i > 0 and nums[i + 1] < nums[i - 1]:
                    nums[i + 1] = nums[i]

        return True
nums = [4,2,1]
s = Solution()
print(s.nonDecreaseArray(nums))
