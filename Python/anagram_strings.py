class Solution(object):
    def __int__(self):
        self.name = 'S->13'

    # Time complexity: O(n)
    # Space complexity: O(k)
    def anagramsString(self, s, p):
        ret = []
        ks = [0] * 26
        kp = [0] * 26
        lp = len(p)
        ll = len(s)
        if ll < lp:
            return []
        for i in range(lp):
            ks[ord(s[i]) - ord('a')] += 1
            kp[ord(p[i]) - ord('a')] += 1
        if (kp == ks): ret.append(0)

        for i in range(1, ll - lp + 1):
            ks[ord(s[i - 1]) - ord('a')] -= 1
            ks[ord(s[i + lp - 1]) - ord('a')] += 1
            if ks == kp:
                ret.append(i)
        return ret
s = 'cbaebabacb'
p = 'abc'

print(Solution().anagramsString(s, p))
