class Solution():
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: O(n)
    # Space complexity: O(n)
    def firstMissingPositiveIntegerA(self, nums):
        first = 1
        d = {}
        for m in nums:
            d[m] = True
        while first in d:
            first += 1
        return first
    
    # We will swap the value that equal to index of array to 
    # exact position. For example [7, 1, -1, 3, 8, 4]. The result will be 
    # the index from 1 to length of array with negative value.
    def firstMissingPositiveIntegerB(self, nums):
        

s = Solution()
nums = [7, 8, 1, 3, -1, 4]
print(s.firstMissingPositiveInteger(nums))
