class Node(object):
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def __repr__(self):
        result = str(self.val)
        if self.left:
            result = result + str(self.left)
        if self.right:
            result = result + str(self.right)
        return result

class Solution():
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: Catalun number of n: (2n)! / (n! * (n+1)!)
    # Space complexity: Catalun number of n: (2n)! / (n! * (n+1)!)
    def GenTree(self, nums):
        if len(nums) == 0:
            return [None]
        if len(nums) == 1:
            return [Node(nums[0])]
        bsts = []
        for n in nums:
            lefts = self.GenTree(range(nums[0], n))
            rights = self.GenTree(range(n+1, nums[-1] + 1))
            for left in lefts:
                for right in rights:
                    root = Node(n, left, right)
                    bsts.append(root)
        return bsts

    # Recursive method
    # Time complexity: O(
    def GenerateBinaryTree(self, n):
        return self.GenTree(range(1, n+1))

n = 4
s = Solution()
print(s.GenerateBinaryTree(n))
