class Solution:
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: O(n)
    # Space complexity: O(1)
    def CountAnatogousArrays(self, arr, lower, upper):
        sum = 0
        min_diff = 0
        max_diff = 0
        for a in arr:
            sum += a
            min_diff = min(sum, min_diff)
            max_diff = max(sum, max_diff)

        max_valid_bound = upper + min_diff if upper + min_diff < upper else upper
        min_valid_bound = lower + max_diff if lower + max_diff > lower else lower

        if max_valid_bound >= min_valid_bound:
            return max_valid_bound - min_valid_bound + 1
        
        return 0
    
arr = [-2, -1, -2, -4]
lower = 3
upper = 10
print(Solution().CountAnatogousArrays(arr, lower, upper))
