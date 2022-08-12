class Solution():
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: O(n)
    # Space complexity: O(n)
    def DistributeBonuses(self, performances):
        n = len(performances)
        bonuses = [1] * n

        for i in range(1, n):
            if performances[i] > performances[i-1]:
                bonuses[i] = bonuses[i-1] + 1

        for i in range(n-2, -1, -1):
            if performances[i] > performances[i+1]:
                bonuses[i] = max(bonuses[i], bonuses[i+1] + 1)

        return bonuses

s = Solution()
performances = [1, 2, 3, 4, 3, 1]
print(s.DistributeBonuses(performances))
