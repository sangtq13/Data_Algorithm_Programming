class Solution:
    def __init__(self):
        self.name = 'S->13'

    def Abbreviation(self, a, b):
        if len(b) > len(a):
            return False
        da = {}
        temp = {}
        for i in range(len(a)):
            if a[i].isupper():
                if a[i] not in temp:
                    da[i] = 0
                    temp[a[i]] = 0
                else:
                    temp[a[i]] += 1
                    da[i] = temp[a[i]]
        temp.clear()
        db = {}
        for i in range(len(b)):
            if b[i] not in temp:
                db[i] = 0
                temp[b[i]] = 0
            else:
                temp[b[i]] += 1
                db[i] = temp[b[i]]
        dp = [[False] * len(a) for _ in range(len(b))]
        if a[0].upper() == b[0]:
            dp[0][0] = True
        for i in range(len(b)):
            for j in range(i, len(a)):
                if i == 0 and j == 0:
                    continue
                if a[j].islower():
                    dp[i][j] = dp[i][j-1] | (a[j].upper() == b[i])
                else:
                    if a[j] == b[i] and da[j] <= db[i]:
                        dp[i][j] = True
        print(da)
        print(db)
        print(dp)
        return dp[-1][-1]
a = 'AbCdE'
b = 'AFE'
print(Solution().Abbreviation(a,b))
