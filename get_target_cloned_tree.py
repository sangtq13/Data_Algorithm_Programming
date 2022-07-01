from collections import deque
class Node(object):
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: O(n)
    # Space complexity: O(n)
    def findNode(self, a, b, node):
        if a == node:
            return b
        if a.left and b.left:
            found = self.findNode(a.left, b.left, node)
            if found:
                return found
        if a.right and b.right:
            found = self.findNode(a.right, b.right, node)
            if found:
                return found
        return None

    # Time complexity: O(n)
    # Space complexity: O(n)
    def getTargetCopy(self, original, cloned, target):
        q = deque()
        q.append((original, cloned))
        while q:
            ori, clone = q.popleft()
            if ori == target:
                return clone
            if ori.left:
                q.append((ori.left, clone.left))
            if ori.right:
                q.append((ori.right, clone.right))

        return None
#  1
# / \
# 2   3
#   / \
#  4*  5
a = Node(1)
a.left = Node(2)
a.right = Node(3)
a.right.left = Node(4)
a.right.right = Node(5)

b = Node(1)
b.left = Node(2)
b.right = Node(3)
b.right.left = Node(4)
b.right.right = Node(5)
print(Solution().getTargetCopy(a, b, a.right.left))
print(Solution().findNode(a, b, a.right.left))
