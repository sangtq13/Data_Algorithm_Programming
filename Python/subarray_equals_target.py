class Solution(object):
    def __init__(self):
        self.name = 'S->13'
        
    # Cumulative Sum method
    # Time complexity: O(n)
    # Space complexity: O(1)
    def subarrayEqualsTargetA(self, nums, target):
        l = len(nums)
        count = 0
        for i in range(l-1):
            sum = 0
            for j in range(i+1, l):
                sum += nums[j]
                if sum == target:
                    count += 1
        return count

    # Time complexity: O(n)
    # Space complexity: O(n)
    def subarrayEqualsTarget(self, nums, target):
        pre_sum = {0: 1}
        s = 0
        count = 0
        for i in range(len(nums)):
            s += nums[i]
            diff = s - target
            if diff in pre_sum:
                count += pre_sum[diff]
            pre_sum[s] = pre_sum.get(s, 0) + 1

        return count
nums = [1, 3, 2, 5, 7, 2, 6, 6]
# nums = [1]
nums = [0]
target = 14
target = 0
print(Solution().subarrayEqualsTarget(nums, target))
