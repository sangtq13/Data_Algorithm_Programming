class Node(object):
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
    def __repr__(self):
        cur = self
        stack = []
        result = ''
        while True:
            if cur:
                stack.append(cur)
                cur = cur.left
            else:
                if stack:
                    node = stack.pop()
                    result += str(node.val) + ' '
                    if node.right:
                        cur = node.right
                else:
                    break
        return result

class Solution():
    def __init__(self):
        self.name = 'S->13'

    def __isBalancedHelper(self, root):
        if not root:
            return (True, 0)
        balancedLeft, leftHeight = self.__isBalancedHelper(root.left)
        balancedRight, rightHeight = self.__isBalancedHelper(root.right)
        if balancedLeft and balancedRight and abs(leftHeight - rightHeight) <= 1:
            return (True, 1 + max(leftHeight, rightHeight))
        return (False, max(leftHeight, rightHeight))

    # Recursive method
    # Time complexity: O(n)
    # Space complexity: O(n) for using recursive function in stack
    def balancedBinaryTreeRecursive(self, root):
        return self.__isBalancedHelper(root)[0]

    # Iterative method: Using post order traversal to
    # store the height of binary tree to dictionary
    # Time complexity: O(n)
    # Space complexity: O(n)
    def balancedBinaryTreeIterative(self, root):
        cur = root
        d = {}
        d[None]  = 0
        stack = []
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
                        if abs(d[node.left] - d[node.right]) > 1:
                            return False
                        d[node] = 1 + max(d[node.left], d[node.right])
                        continue
                    if stack and node.right and node.right == stack[-1]:
                        stack.pop()
                        cur = node.right
                        stack.append(node)
                else:
                    break

        return True
#            1
#           / \
#          2   3
#         / \ / \
#        4  5 6  7
root = Node(1, Node(2, Node(4), Node(5)), Node(3, Node(6), Node(7)))
print(root)
s = Solution()
print(s.balancedBinaryTreeRecursive(root))
print(s.balancedBinaryTreeIterative(root))
