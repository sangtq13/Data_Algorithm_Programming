class Solution():
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: O(n)
    # Space complexity: O(n)
    def IsIsomorphic(self, s, t):
        if len(s) != len(t):
            return False

        d1 = {}
        d2 = {}
        for i in range(len(s)):
            if s[i] not in d1:
                d1[s[i]] = t[i]
            else:
                if d1[s[i]] != t[i]:
                    return False
            if t[i] not in d2:
                d2[t[i]] = s[i]
            else:
                if d2[t[i]] != s[i]:
                    return False
        return True

s = 'abc'
t = 'def'
print(Solution().IsIsomorphic(s, t))
print(Solution().IsIsomorphic('aaaaa', 'bbbba'))
