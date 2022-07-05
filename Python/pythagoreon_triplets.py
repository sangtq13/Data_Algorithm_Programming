class Solution(object):
    def __init__(self):
        self.name = 'S->13'

    # Brute force method will take O(n^3) time complexity and O(1) for
    # space complexity. But in this implementation, we will not mention
    # this method. We will try another solution using set data structure
    # to increase performance
    # Time complexity: O(n^2)
    # Space complexity: O(n)
    def pythagoreonTriplets(self, arr):
        squares = set([n*n for n in arr])
        ret = []
        for a in arr:
            for b in arr:
                if a*a + b*b in squares:
                    ret.append([a,b,int((a*a+b*b)**0.5)])
        return ret

arr = [1,2,3,4,5,12,13,16,14]
s = Solution()
print(s.pythagoreonTriplets(arr))
