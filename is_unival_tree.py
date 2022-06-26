from collections import deque
class Node(object):
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution():
    def __init__(self):
        self.name = 'S->13'

    # Recursive method:
    # Time complexity: O(n)
    # Space complexity: O(n)
    def __isUnivalTreeHelper(self, root):
        if not root:
            return True
        if root.left and root.val != root.left.val:
                return False
        if root.right and root.val != root.right.val:
                return False
        return self.__isUnivalTreeHelper(root.left) and self.__isUnivalTreeHelper(root.right)

    def isUnivalTreeRecursive(self, root):
        return self.__isUnivalTreeHelper(root)

    # Iterative method using queue
    # Time complexity: O(n)
    # Space complexity: O(n)
    def isUnivalTreeIterative(self, root):
        q = deque()
        q.append(root)
        while q:
            node = q.popleft()
            if node.left:
                if node.val != node.left.val:
                    return False
                else:
                    q.append(node.left)
            if node.right:
                if node.val != node.right.val:
                    return False
                else:
                    q.append(node.right)
        return True

root = Node(1, Node(1, Node(1)), Node(1, Node(1), Node(1)))
s = Solution()
print(s.isUnivalTreeRecursive(root))
print(s.isUnivalTreeIterative(root))
