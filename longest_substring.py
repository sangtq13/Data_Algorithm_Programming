from collections import OrderedDict
class Solution(object):
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: O(n)
    # Space complexity: O(k)
    def longestSubstringA(self, s):
        if not s: return 0
        longest = 1
        l = len(s)
        start = 0
        d = {}
        for i in range(0, l):
            if s[i] not in d:
                d[s[i]] = i
            else:
                longest = max(longest, i - start)
                while s[start] != s[i]:
                    d.pop(s[start])
                    start += 1
                start += 1
                d[s[i]] = i
        if start != l - 1:
            longest = max(longest, l - start)
        return longest

    # Time complexity: O(n)
    # Space complexity: O(k)
    def longestSubstringB(self, s):
        longest = 0
        l = len(s)
        start = 0
        d = {}
        for i in range(l):
            d[s[i]] = d.get(s[i], 0) + 1
            while d[s[i]] > 1:
                d[s[start]] -= 1
                start += 1
            longest = max(longest, i - start + 1)
        return longest

print(Solution().longestSubstringA("aabcbbeacc"))
print(Solution().longestSubstringA("abba"))
print(Solution().longestSubstringB("abcabcbb"))
print(Solution().longestSubstringB(" "))
