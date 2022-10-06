class Solution:
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: O(m*n)
    # Space complexity: O(m*n)
    def Abbreviation(self, a, b):
        if len(b) > len(a):
            return False
        upper_num = 0
        dp = [[False] * len(a) for _ in range(len(b))]

        for i in range(0, len(a)):
            if a[i].islower():
                if a[i].upper() == b[0] and upper_num == 0:
                    dp[0][i] = True
                else:
                    dp[0][i] = dp[0][i-1]
            else:
                if a[i] == b[0] and upper_num == 0:
                    dp[0][i] = True
                upper_num += 1

        for i in range(1, len(b)):
            for j in range(i, len(a)):
                if a[j].islower():
                    if a[j].upper() == b[i]:
                        dp[i][j] = dp[i][j-1] | dp[i-1][j-1]
                    else:
                        dp[i][j] = dp[i][j-1]
                else:
                    if a[j] != b[i]:
                        dp[i][j] = False
                    else:
                        dp[i][j] = dp[i-1][j-1]

        if dp[-1][-1]:
            return 'YES'
        return 'NO'
a = 'daBcde'
b = 'ABC'
print(Solution().Abbreviation(a,b))
