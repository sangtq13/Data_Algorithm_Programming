class Solution(object):
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: O(n)
    # Space complexity: O(k)
    def roman2NumberA(self, s):
        l = len(s)
        roman = {'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000,'IV':4,'IX':9,'XL':40,'XC':90,'CD':400,'CM':900}
        num = 0
        i = 0
        while i < l:
            if i+1 < l and s[i:i+2] in roman:
                num += roman[s[i:i+2]]
                i += 2
            else:
                num += roman[s[i]]
                i += 1
        return num

    # Time complexity: O(n)
    # Space complexity: O(k)
    def roman2NumberB(self, s):
        roman = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        pre = 0
        num = 0
        for i in s[::-1]:
            cur = roman[i]
            num += (-cur if cur < pre else cur)
            pre = cur
        return num


print(Solution().roman2NumberA('MCMIV'))
print(Solution().roman2NumberB('MCMIV'))
# 1904
print(Solution().roman2NumberA('CDXLIII'))
print(Solution().roman2NumberB('CDXLIII'))
# 443
