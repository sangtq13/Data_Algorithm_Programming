class Solution:
    def __partition(self, nums, left, right):
        pivot = (left + right) // 2
        nums[left], nums[pivot] = nums[pivot], nums[left]
        index = left
        for i in range(left+1, right + 1):
            if nums[i] < nums[left]:
                index += 1
                nums[i], nums[index] = nums[index], nums[i]
        nums[index], nums[left] = nums[left], nums[index]
        return index

    # Time complexity: O(n)
    # Space complexity: O(1)
    def findKthLargest(self, nums, k):
        left = 0
        right = len(nums) - 1
        while left <= right:
            pivot = self.__partition(nums, left, right)
            if pivot == len(nums)-k:
                return nums[pivot]
            elif pivot < len(nums)-k:
                left = pivot + 1
            else:
                right = pivot - 1

nums = [2,1]
nums = [3,2,1,5,6,4]
k = 2
print(Solution().findKthLargest(nums, k))
