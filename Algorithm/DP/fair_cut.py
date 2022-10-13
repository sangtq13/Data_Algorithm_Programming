class Solution:
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: O(k*n)
    # Space complexity: O(k*n)
    def FairCut(self, arr, k):
        n = len(arr)
        if k > n - k:
            k = n - k
        arr.sort()
        dp = [[float('inf') for i in range(0, k + 2)] for j in range(0, n + 1)]
        dp[0][0] = 0
        for i in range(n):
            for j in range(min(i+1,k+1)):
                # Put arr[i] to I, it will have (i-j) number less than arr[i] in set J and 
                # (n-k-(i-j)) number greater than arr[i] in set J for future calculation 
                to_i = dp[i][j] + (i - j) * arr[i] - (n - k - (i - j)) * arr[i]
                # Put arr[i] to J, it will have (j) number less than arr[i] in set I and 
                # (k-j)) number greater than arr[i] in set I for future calculation 
                to_j = dp[i][j] + j * arr[i] - (k - j) * arr[i]
                if dp[i + 1][j + 1] > to_i:
                    dp[i+1][j+1] = to_i
                if dp[i + 1][j] > to_j:
                    dp[i+1][j] = to_j

        return dp[n][k]


arr = [4, 3, 1, 2]
k = 2
print(Solution().FairCut(arr, k))
