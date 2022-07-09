class Solution():
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: O(n)
    # Space complexity: O(n)
    def SortedSquareNumber(self, nums):
        ans = []
        left = -1
        for i in range(len(nums)):
            if nums[i] <= 0:
                left += 1
            else:
                break
        right = left + 1

        while left > -1 and right < len(nums):
            left_square = nums[left] * nums[left]
            right_suare = nums[right] * nums[right]
            if left_square < right_suare:
                ans.append(left_square)
                left -= 1
            else:
                ans.append(right_suare)
                right += 1
        if (left >= 0):
            for i in range(left, -1, -1):
                ans.append(nums[i]*nums[i])
        if (right < len(nums)):
            for i in range(right, len(nums)):
                ans.append(nums[i]*nums[i])
        return ans

nums = [-5, -3, -1, 1, 4, 5]
print(Solution().SortedSquareNumber(nums))
