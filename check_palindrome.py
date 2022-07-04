class Solution(object):
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: O(n)
    # Space complexity: O(n)
    def checkPalindrome(self, s):
        d = {}
        for c in s:
            d[c] = d.get(c, 0) + 1
        count = 0
        for k, v in d.items():
            if v % 2 == 1:
                count += 1
            if count > 1:
                return False
        return True
s = 'foxfo'
print(Solution().checkPalindrome(s))
