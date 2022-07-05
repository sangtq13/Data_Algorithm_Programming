class Solution(object):
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: O(n)
    # Space complexity: O(1)
    def maxProfit(self, prices):
        start = prices[0]
        maxPro = 0
        for i in range(1, len(prices)):
            if prices[i] < prices[i - 1]:
                maxPro = max(maxPro, prices[i - 1] - start)
                start = min(start, prices[i])

        return max(maxPro, prices[-1] - start)

prices = [2,3,5,8,7,1,5,3,6,4]
print(Solution().maxProfit(prices))
