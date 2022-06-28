from collections import deque
class Node(object):
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def __repr__(self):
        root = self
        stack = [root]
        result = ''
        while stack:
            node = stack.pop()
            result += str(node.val) + ' '
            if node.right:
                stack.append(node.right)
            if node.left:
                stack.append(node.left)
        return result

class Solution():
    def __int__(self):
        self.name = 'S->13'

    # Recursive method
    # Time complexity: O(n)
    # Space complexity: O(n)
    def invertTree(self, root):
        if not root:
            return
        left = self.invertTree(root.left)
        right = self.invertTree(root.right)
        root.left, root.right = right, left

        return root

    # Iterative method using postorder traversal
    # Time complexity: O(n)
    # Space complexity: O(n)
    def invertTreeIterative(self, root):
        stack = []
        d = {}
        d[None] = 1
        cur = root
        while True:
            if cur:
                if cur.right:
                    stack.append(cur.right)
                stack.append(cur)
                cur = cur.left
            else:
                if stack:
                    node = stack.pop()
                    if node.left in d and node.right in d:
                        node.left, node.right = node.right, node.left
                        d[node] = 1
                        continue
                    if stack and node.right and node.right == stack[-1]:
                        stack.pop()
                        cur = node.right
                        stack.append(node)
                else:
                    break
        return root

    # Iterative method using BFS
    def invertTreeIterativeBFS(self, root):
        q = deque()
        q.append(root)
        while q:
            node = q.popleft()
            node.left, node.right = node.right, node.left
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)
        return root

root = Node(1, Node(2, Node(4), Node(5)), Node(3, Node(6), Node(7)))
print(root)
print(Solution().invertTree(root))
print(Solution().invertTreeIterative(root))
print(Solution().invertTreeIterativeBFS(root))
