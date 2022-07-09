from functools import cmp_to_key
class Solution():
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: O(nlogn)
    # Space complexity: O(logn) to O(n) depend on sorting method of python
    def MakeLargestNumber(self, nums):
        nums.sort(key=cmp_to_key(
            lambda a, b:
            1 if str(a) + str(b) < str(b) + str(a)
            else -1
        ))
        if nums[0] == 0: return '0'
        return ''.join(map(str, nums))

nums = [17, 7, 2, 45, 72]
print(Solution().MakeLargestNumber(nums))
