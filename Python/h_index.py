class Solution():
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: O(n)
    # Space complexity: O(n)
    def HIndex(self, citations):
        n = len(citations)
        frequencies = [0] * (n + 1)
        for c in citations:
            if c >= n:
                frequencies[n] += 1
            else:
                frequencies[c] += 1
        i = n
        total = 0
        while i >= 0:
            total += frequencies[i]
            if total >= i:
                return i
            i -= 1
citations = [3, 0, 6, 1, 4, 4, 5]
citations = [3, 0, 6, 1, 4, 4, 5]
print(Solution().HIndex(citations))
