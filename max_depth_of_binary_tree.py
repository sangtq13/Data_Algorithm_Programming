from collections import deque
class Node(object):
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def __repr__(self):
        root = self
        result = ''
        q = deque()
        q.append(root)
        while q:
            node = q.popleft()
            result += str(node.val) + ''
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)
        return result

class Solution():
    def __init__(self):
        self.name = 'S->13'

    # Recursive method
    # Time complexity: O(n)
    # Space complexity: O(n) for using stack of recursive function
    def maxDepth(self, root):
        if root == None:
            return 0
        return 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))

    def maxDepthIterative(self, root):
        maxDepth = 0
        stack = [(root, 1)]
        while stack:
            node, depth = stack.pop()
            if depth > maxDepth:
                maxDepth = depth

            if node.right:
                stack.append((node.right, 1+depth))
            if node.left:
                stack.append((node.left, 1+depth))

        return maxDepth

root = Node(1, Node(2, Node(4, Node(5, Node(6)))), Node(3))
s = Solution()
print(root)
print(s.maxDepth(root))
print(s.maxDepthIterative(root))
