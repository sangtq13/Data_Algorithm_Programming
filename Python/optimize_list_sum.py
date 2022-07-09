class Solution():
    def __init__(self, nums):
        self.name = 'S->13'
        self.sums = [0]
        sum = 0
        for n in nums:
            sum += n
            self.sums.append(sum)

    # Time complexity: O(1)
    # Space complexity: O(n)
    def OptimizeListSum(self, start, end):
        return self.sums[end] - self.sums[start]

nums = [1,2,3,4,5,6,7,8,9,10]
s = Solution(nums)
print(s.OptimizeListSum(2,5))
