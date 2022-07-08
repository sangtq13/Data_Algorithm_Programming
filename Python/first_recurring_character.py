class Solution(object):
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: O(n)
    # Space complexity: O(n)
    def firstRecurringCharacter(self, s):
        d = set()
        for m in s:
            if m in d:
                return m
            else:
                d.add(m)
        return None
s = Solution()
str = 'qwertty'
print(s.firstRecurringCharacter(str))
str = 'qwerty'
print(s.firstRecurringCharacter(str))
