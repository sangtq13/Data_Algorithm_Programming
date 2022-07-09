class Solution(object):
    def __init__(self):
        self.name = 'S->13'
 
    // Time complexity: O(n)
    // Space complexity: O(n)
    def permuteCost(self, n):
        ans = []
        for i in range(1,n+1,2):
            ans+=[i]
            while(2*i<=n):
                ans+=[2*i]
                i=2*i
        return ans

print(Solution().permuteCost(11))
