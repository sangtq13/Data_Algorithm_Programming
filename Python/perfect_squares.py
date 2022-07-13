class Solution():
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: O(nlogn)
    # Space complexity: O(n)
    def SumOfSquares(self, n):
        i = 1
        squares = []
        while i * i <= n:
            squares.append(i*i)
            i += 1

        min_sums = [n] *  (n+1)
        min_sums[0] = 0
        for i in range(0, n+1):
            for s in squares:
                if i + s < n+1:
                    min_sums[i+s] = min(min_sums[i+s], min_sums[i] + 1)
        return min_sums[-1]
n = 4
print(Solution().SumOfSquares(n))
