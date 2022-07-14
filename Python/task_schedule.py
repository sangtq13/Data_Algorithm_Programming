import heapq
class Solution():
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: O(n)
    # Space complexity: O(n) in worst case
    def TaskSchedule1(self, tasks, countdown):
        count = {}
        result = 0
        for task in tasks:
            count[task] = count.get(task, 0) + 1
        heap = []
        for k, v in count.items():
            heapq.heappush(heap, (-v, k))
        while heap:
            wait_list = []
            k = countdown + 1
            while heap and k:
                count, task = heapq.heappop(heap)
                if count < -1:
                    wait_list.append((count + 1, task))
                result += 1
                k -= 1
            for w in wait_list:
                heapq.heappush(heap, w)
            if (heap): result += k

        return result

    # Using hash map with greedy
    # Time complexity: O(n)
    # Space complexity: O(n) in worst case
    def TaskSchedule2(self, tasks, countdown):
        count = {}
        mc = 0
        for task in tasks:
            count[task] = count.get(task, 0) + 1
            if mc < count[task]: mc = count[task]
        result = mc * (countdown + 1) - 1
        for k , v in count.items():
            if v == mc: result += 1

        return max(len(tasks), result)
tasks = [1, 1, 1, 2, 2, 2, 3, 3, 3]
countdown = 2
s = Solution()
print(s.TaskSchedule2(tasks, countdown))
