class Solution():
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: O(n)
    # Space complexity: O(1)
    def Equals(self, nums):
        posibilities = [0] * 5
        min_num = min(nums)
        for i in range(5):
            for num in nums:
                diff = num - min_num
                posibilities[i] += int(diff / 5) + int((diff % 5) / 2) + int(((diff % 5) % 2) / 1)
            min_num -= 1
        return min(posibilities)

nums = [7, 10, 12]
s = Solution()
print(s.Equals(nums))
