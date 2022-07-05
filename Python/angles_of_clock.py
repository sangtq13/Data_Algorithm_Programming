class Solution(object):
    def __init__(self):
        self.name = 'S->13'

    def anglesOfClock(self, hour, minutes):
        hour_location = hour % 12 + float(minutes) / 60
        angle = abs(float(minutes) / 5 - hour_location) * 30
        return min(angle, 360 - angle)

hour = 3
minute = 5
print(Solution().anglesOfClock(hour, minute))
