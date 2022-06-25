class Node(object):
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution():
    def __init__(self):
        self.name = 'S->13'

    # Recursive method
    # Time complexity: O(n) in worst case
    # Space complexity: O(n) in worst case
    def __getAllValuesHelper(self, root, height):
        if height == 1:
            return [root.val]
        result = []
        if root.left:
            result += self.__getAllValuesHelper(root.left, height-1)
        if root.right:
            result += self.__getAllValuesHelper(root.right, height-1)
        return result

    def getValuesAtHeightRecursive(self, root, height):
        return self.__getAllValuesHelper(root, height)

    # Iterative method using stack
    # Time complexity: O(n) in worst case
    # Space complexity: O(n) in worst case
    def getValuesAtHeightIterative(self, root, height):
        stack = [(root, 1)]
        ret = []
        while stack:
            node, depth = stack.pop()
            if depth == height:
                ret.append(node.val)
                continue
            if node.right:
                stack.append((node.right, depth+1))
            if node.left:
                stack.append((node.left, depth+1))

        return ret
#     1
#    / \
#   2   3
#  / \   \
# 4   5   7
root = Node(1, Node(2, Node(4), Node(5)), Node(3, Node(7)))
print(Solution().getValuesAtHeightRecursive(root, 3))
print(Solution().getValuesAtHeightIterative(root, 3))
