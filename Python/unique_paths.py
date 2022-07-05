class Solution(object):
    def __init__(self):
        self.name = 'S->13'

    # Using stack and DFS method
    # Time complexity: O(m*n)
    # Space complexity: O(m*n)
    def uniquePaths(self, m, n):
        stack = [(0, 0, 1)]
        count = 0
        direction = [(1,0), (0,1)]

        while stack:
            x, y, l = stack.pop()
            if l == m+n-1:
                count += 1
            else:
                for d in direction:
                    nX = x + d[0]
                    nY = y + d[1]
                    if 0 <= nX < m and 0 <= nY < n:
                        stack.append((nX, nY, l+1))
        return count

    # Recursive method
    # Time complexity: O(2^m*n)
    # Space complexity: O(2^m*n) for recursive stack
    def uniquePaths(self, m, n):
        if m == 1 or n == 1:
            return 1
        return self.uniquePaths(m - 1, n) + self.uniquePaths(m, n - 1)

    # Using dynamic programming method
    # Time complexity: O(m*n)
    # Space complexity: O(m*n)
    def uniquePathsDP(self, m, n):
        dp = [[1] * n] * m
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = dp[i-1][j] + dp[i][j-1]
        return dp[-1][-1]

m = 3
n = 7
s = Solution()
print(s.uniquePaths(m, n))
print(s.uniquePathsDP(m, n))
