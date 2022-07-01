class Solution(object):
    def __init__(self):
        self.name = 'S->13'

    # Using sorting method
    # Time complexity: O(nlogn)
    # Space complexity: O(n) in worst case to storage result
    def mergeIntervals(self, intervals):
        intervals.sort()
        ret = []
        start = intervals[0][0]
        end = intervals[0][1]
        for i in intervals:
            if i[0] > end:
                ret.append([start, end])
                start, end = i[0], i[1]
            else:
                start, end = min(start, i[0]), max(end, i[1])
        ret.append([start, end])
        return ret

intervals = [[1, 3], [5, 8], [4, 10], [20, 25], [2, 6], [6, 7]]
# intervals = [[1,4],[0,4]]
# intervals = [[1,4],[2,3]]
intervals = [[2,3],[4,5],[6,7],[8,9],[1,10]]
print(Solution().mergeIntervals(intervals))
