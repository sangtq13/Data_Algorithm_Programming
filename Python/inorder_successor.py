class Node(object):
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    # Postorder traversal
    def __repr__(self):
        result = ''
        cur = self
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
                    if stack and node.right and node.right == stack[-1]:
                        stack.pop()
                        cur = node.right
                        stack.append(node)
                    else:
                        result += str(node.val) + ' '
                else:
                    break
        return result

class Solution(object):
    def __init__(self):
        self.name = 'S->13'

    def __inorderSuccessorHelper(self, root, ret, value):
        if not root:
            return [None, None]
        if root.val > value:
            ret = root
            return self.__inorderSuccessorHelper(root.left, ret, value)
        elif root.val < value:
            return self.__inorderSuccessorHelper(root.right, ret, value)
        else:
            return [ret, root.right]

    # Recursive method:
    # Time complexity: O(n) in worst case
    # Space complexity: O(n) in worst case
    def inorderSuccessorRecursive(self, root, value):
        a, b = self.__inorderSuccessorHelper(root, None, value)
        if b != None:
            pre = b
            while b:
                pre = b
                b = b.left
            return pre
        return a

    # Using search in BST
    # Time complexity: O(n) in worst case
    # Space complexity: O(1)
    def inorderSuccessorB(self, root, value):
        cur = root
        ret = 0
        while True:
            if cur.val > value:
                ret = cur
                cur = cur.left
            elif cur.val < value:
                cur = cur.right
            else:
                if cur.right:
                    pre = cur.right
                    cur = cur.right
                    while cur:
                        pre = cur
                        cur = cur.left
                    return pre
                else:
                    return ret
        return None

    # Inorder Traversal method
    # Time complexity: O(n)
    # Space complexity: O(n)
    def inorderSuccessorA(self, root, value):
        cur = root
        stack = []
        found = False
        while True:
            if cur:
                stack.append(cur)
                cur = cur.left
            else:
                if stack:
                    node = stack.pop()
                    if node.val > value and found:
                        return node
                    if node.val == value:
                        found = True
                    if node.right:
                        cur = node.right
                else:
                    break
        return None

#     4
#    / \
#   2   8
#  /   / \
# 1   5   9
#      \
#       7
root = Node(4, Node(2, Node(1)), Node(8, Node(5, None, Node(7)), Node(9)))
print(root)
s = Solution()
print(s.inorderSuccessorA(root, 4))
print(s.inorderSuccessorA(root, 8))
print(s.inorderSuccessorA(root, 7))
print(s.inorderSuccessorA(root, 1))

print(s.inorderSuccessorB(root, 4))
print(s.inorderSuccessorB(root, 8))
print(s.inorderSuccessorB(root, 7))
print(s.inorderSuccessorB(root, 1))
#
print(s.inorderSuccessorRecursive(root, 4))
print(s.inorderSuccessorRecursive(root, 8))
print(s.inorderSuccessorRecursive(root, 7))
print(s.inorderSuccessorRecursive(root, 1))
