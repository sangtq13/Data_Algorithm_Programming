from collections import defaultdict
import heapq
class Solution(object):
    def __init__(self):
        self.name = 'S->13'

    def heapify(self, nums, i, l):
        largest = i
        left = 2 * i + 1
        right = 2 * i + 2
        if left < l and nums[left] > nums[largest]:
            largest = left
        if right < l and nums[right] > nums[largest]:
            largest = right
        if largest != i:
            nums[largest], nums[i] = nums[i], nums[largest]
            self.heapify(nums, largest, l)

        return nums

    def buildHeap(self, nums):
        l = len(nums)
        startIdx = len(nums) // 2 - 1
        for i in range(startIdx, -1, -1):
            self.heapify(nums, i, l)
        return nums

    def popMax(self, nums):
        max = nums[0]
        nums[0] = nums[-1]
        self.heapify(nums, 0, len(nums)-1)

        return max

    # Self build max heap method
    # Time complexity: O(n)
    # Space complexity: O(n)
    def topKFrequentElementsA(self, nums, k):
        ret = []
        count = defaultdict(int)
        for n in nums:
            count[n] += 1
        heap = []
        for n, c in count.items():
            heap.append((c, n))
        self.buildHeap(heap)
        print(heap)
        for i in range(k):
            max = self.popMax(heap)
            ret.append(max[1])
        return ret

    # Using heapq from python
    # Time complexity: O(n)
    # Space complexity: O(n)
    def topKFrequentElementsB(self, nums, k):
        ret = []
        count = defaultdict(int)
        for n in nums:
            count[n] += 1

        heap = []
        for n, c in count.items():
            heap.append((-c, n))
        heapq.heapify(heap)
        print(heap)
        for _ in range(k):
            ret.append(heapq.heappop(heap)[1])

        return ret

nums = [1,1,1,2,4,3,5,1,8,9,52,2,3]
nums1 = [1,1,1,2,4,3,5,1,8,9,52,2,3]
k = 6
s = Solution()
print(s.buildHeap(nums))
print(s.topKFrequentElementsA(nums, k))
print(s.topKFrequentElementsB(nums1, k))
