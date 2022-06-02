from collections import deque

class Node(object):
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

    def maximumDepth(self):
        maxDepth = 1
        depth = {}
        depth[self.value] = 1
        queue = deque([self])

        while queue:
            node = queue.popleft()
            if node.left:
                depth[node.left.value] = depth[node.value] + 1
                if depth[node.left.value] > maxDepth:
                    maxDepth = depth[node.left.value]
                queue.append(node.left)
            if node.right:
                depth[node.right.value] = depth[node.value] + 1
                if depth[node.right.value] > maxDepth:
                    maxDepth = depth[node.right.value]
                queue.append(node.right)

        return maxDepth

    def __isMirror(self, root1, root2):
        if not root1 and not root2:
            return True
        if not root1 or not root2:
            return False
        if root1.value != root2.value:
            return False

        return self.__isMirror(root1.left, root2.right) and self.__isMirror(root1.right, root2.left)

    def symetricTree(self, root):
        if not root or (not root.left and not root.right):
            return True
        if not root.left or not root.right:
            return False
        return self.__isMirror(self, self);

    def symetricTreeIterative(self, root):
        if not root or (not root.left and not root.right):
            return True
        if not root.left or not root.right:
            return False
        left_queue = deque([root.left])
        right_queue = deque([root.right])

        while left_queue and right_queue:
            left_side_node = left_queue.pop()
            right_side_node = right_queue.pop()
            if left_side_node.value != right_side_node.value:
                return False
            if left_side_node.left:
                left_queue.append(left_side_node.left)
            if left_side_node.right:
                left_queue.append(left_side_node.right)
            if right_side_node.right:
                right_queue.append(right_side_node.right)
            if right_side_node.left:
                right_queue.append(right_side_node.left)

        if left_queue or right_queue:
            return False

        return True
#       1
#      / \
#     2   2
#    / \ / \
#   3  4 4  3


root = Node(1, Node(2, Node(3), Node(4)), Node(2, Node(4), Node(3)))
# root = Node(1, Node(2), Node(2, Node(4), Node(3)))
print(root.maximumDepth())
print(root.symetricTreeIterative(root))
print(root.symetricTree(root))
