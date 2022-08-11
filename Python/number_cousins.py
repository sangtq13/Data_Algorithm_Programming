from collections import *
class Node(object):
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def __repr__(self):
        result = str(self.val)
        if self.left:
            result += str(self.left.val)
        if self.right:
            result += str(self.right.val)

class Solution():
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: O(n)
    # Space complexity: O(n)
    def NumberCousinsA(self, root, target):
        q = deque()
        q.append((root, None, 1))
        d = defaultdict(list)
        parent_k = None
        depth_k = 0
        while q:
            node, parent, depth = q.popleft()
            if node == target:
                depth_k = depth
                parent_k = parent
            d[depth].append(node.val)

            if node.left:
                q.append((node.left, node, depth + 1))
            if node.right:
                q.append((node.right, node, depth + 1))
        if parent_k.left:
            d[depth_k].remove(parent_k.left.val)
        if parent_k.right:
            d[depth_k].remove(parent_k.right.val)

        return d[depth_k]

    def FindNode(self, root, target, parent, height):
        if not root:
            return None
        if root == target:
            return (parent, height)
        return self.FindNode(root.left, target, root, height + 1) or \
                self.FindNode(root.right, target, root, height + 1)

    def NodesAtHeight(self, root, exclude, height):
        if not root or root == exclude:
            return []
        if height == 1:
            return [root.val]

        return self.NodesAtHeight(root.left, exclude, height-1) + self.NodesAtHeight(root.right, exclude, height-1)

    # Time complexity: O(n)
    # Space complexity: O(n)
    def NumberCousinsB(self, root, target):
        parent, height = self.FindNode(root, target, None, 1)
        return self.NodesAtHeight(root, parent, height)

#     1
#    / \
#   2   3
#  / \    \
# 4   6    5
root = Node(1)
root.left = Node(2)
root.left.left = Node(4)
root.left.right = Node(6)
root.right = Node(3)
root.right.right = Node(5)

s = Solution()
print(s.NumberCousinsA(root, root.left.right))
print(s.NumberCousinsB(root, root.left.right))
