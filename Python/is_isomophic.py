class Solution():
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: O(n)
    # Space complexity: O(n)
    def IsIsomorphic1(self, s, t):
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

    def convert(self, s):
        d = {}
        result = []
        for i in range(len(s)):
            if s[i] not in d:
                d[s[i]] = i
                result.append(i)
            else:
                result.append(d[s[i]])
        return result
    # Time complexity: O(n)
    # Space complexity: O(n)
    def IsIsomorphic2(self, s, t):
        return self.convert(s) == self.convert(t)
s = 'abc'
t = 'def'
print(Solution().IsIsomorphic1(s, t))
print(Solution().IsIsomorphic1('aaaaa', 'bbbba'))
print(Solution().IsIsomorphic2(s, t))
print(Solution().IsIsomorphic2("bbbaaaba", "aaabbbba"))
