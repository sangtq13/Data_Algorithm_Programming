import heapq
class Solution(object):
    def __init__(self):
        self.name = 'S->13'

    # Using sorting method by end time
    # Time complexity: O(nlogn)
    # Space complexity: O(1)
    def meetingRooms(self, intervals):
        count = 1
        preEnd = 0
        intervals.sort(key = lambda x: x[1])
        for interval in intervals:
            if interval[0] < preEnd:
                count += 1
            preEnd = interval[1]

        return count

    # This method use sorting method by start time.
    # Use heap to keep track of end time
    # Time complexity: O(nlogn)
    # Space complexity: O(n)
    def meeting_rooms(self, meetings):
        meetings.sort(key=lambda x: x[0])
        meeting_ends = []
        max_rooms = 0

        for meeting in meetings:
            while meeting_ends and meeting_ends[0] <= meeting[0]:
                heapq.heappop(meeting_ends)
            heapq.heappush(meeting_ends, meeting[1])
            max_rooms = max(max_rooms, len(meeting_ends))
        return max_rooms


intervals = [[1, 5], [2, 6], [3, 4], [8, 10], [9, 11]]
s = Solution()
print(s.meetingRooms(intervals))
print(s.meetingRooms([[0, 10], [10, 20]]))
# 1
print(s.meetingRooms([[20, 30], [10, 21], [0, 50], [8, 15]]))
# 3
print(s.meeting_rooms([[20, 30], [10, 21], [0, 50], [8, 15]]))
