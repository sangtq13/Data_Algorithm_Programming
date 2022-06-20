import heapq
import random
class Solution(object):
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: O(n)
    # Space complexity: O(1)
    def kthLargestElementA(self, nums, k):
        l = len(nums)
        heapq.heapify(nums)
        for _ in range(l-k):
            heapq.heappop(nums)
        return heapq.heappop(nums)

    # Time complexity: O(n)
    # Space complexity: O(1)
    def kthLargestElementB(self, nums, k):
        return heapq.nlargest(k, nums)[-1]

    # Time complexity: O(n + n/2 + n/4 + ...) = O(n)
    # Space complexity: O(1)
    def kthLargestElementC(self, nums, k):
        def select(nums, left, right, index):
            if left == right:
                return nums[left]
            pivot = random.randint(left, right)
            j = left
            nums[pivot], nums[left] = nums[left], nums[pivot]
            for i in range(left + 1, right + 1):
                if nums[i] < nums[left]:
                    j += 1
                    nums[i], nums[j] = nums[j], nums[i]
            nums[j], nums[left] = nums[left], nums[j]
            if index == j:
                return nums[j]
            elif j < index:
                return select(nums, j + 1, right, index)
            else:
                return select(nums, left, j - 1, index)

        return select(nums, 0, len(nums) - 1, len(nums) - k)


nums = [3, 5, 2, 4, 6, 8]
k = 3
s = Solution()
print(s.kthLargestElementA([3, 5, 2, 4, 6, 8], 3))
print(s.kthLargestElementB([3, 5, 2, 4, 6, 8], 3))
print(s.kthLargestElementC([3, 5, 2, 4, 6, 8], 3))
