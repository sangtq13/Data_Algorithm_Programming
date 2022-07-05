class Solution:
    def productExceptSelf(self, nums):
        n = len(nums)
        result = [1] * n
        p = 1
        for i in range(n-2, -1, -1):
            print(i)
            p *= nums[i+1]
            result[i] = p

        p = 1
        for i in range(1, n):
            p *= nums[i-1]
            result[i] *= p

        return result
print(Solution().productExceptSelf([1, 2, 0, 0, 4]))
