import heapq
class Solution():
    def __init__(self):
        self.name = 'S->13'

    def GetHeapMedian(self, heap):
        tmp = []
        len_even = False
        if len(heap) % 2 == 1:
            k = (len(heap) - 1) // 2
        else:
            len_even = True
            k = len(heap) / 2 - 1
        while k:
            tmp.append(heapq.heappop(heap))
            k -= 1
        if len_even == False:
            median = heapq.heappop(heap)
            tmp.append(median)
        else:
            first_number = heapq.heappop(heap)
            second_number = heapq.heappop(heap)
            median = (first_number + second_number) / 2
            tmp += [first_number, second_number]
        for i in range(len(tmp)):
            heapq.heappush(heap, tmp[i])
        return median

    # Using min heap method
    # Time complexity: O(nlogn)
    # Space complexity: O(n)
    def RunningMedianA(self, nums):
        medians = []
        heap = []
        for i in range(len(nums)):
            heapq.heappush(heap, nums[i])
            medians.append(self.GetHeapMedian(heap))
        return medians

    def __Rebalance(self, min_heap, max_heap):
        if len(min_heap) > len(max_heap) + 1:
            heapq.heappush(max_heap, -heapq.heappop(min_heap))
        elif len(min_heap) + 1 < len(max_heap):
            heapq.heappush(min_heap, -heapq.heappop(max_heap))

    # Using combination of min heap and max heap
    # Time complexity: O(nlogn)
    # Space complexity: O(n)
    def RunningMedianB(self, nums):
        medians = []
        min_heap = []
        max_heap = []
        current_median = 0
        for i in range(len(nums)):
            if (len(medians)):
                current_median = medians[-1]
            if nums[i] > current_median:
                heapq.heappush(min_heap, nums[i])
            else:
                heapq.heappush(max_heap, -nums[i])
            self.__Rebalance(min_heap, max_heap)
            if len(min_heap) == len(max_heap):
                medians.append((min_heap[0] + (-max_heap[0])) / 2)
            elif len(min_heap) > len(max_heap):
                medians.append(min_heap[0])
            else:
                medians.append(-max_heap[0])
        return medians
nums = [2, 1, 4, 7, 2, 0, 5]
print(Solution().RunningMedianA(nums))
print(Solution().RunningMedianB(nums))
# [2, 1.5, 2, 3, 2, 2, 2]
