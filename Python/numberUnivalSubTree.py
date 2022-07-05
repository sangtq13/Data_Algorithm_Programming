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

    # Recursive method
    # Time complexity: O(n)
    # Space complexity: O(n)
    def __numberUnivalSubTreeHelper(self, root, count):
        if not root:
            return True

        leftUnival = self.__numberUnivalSubTreeHelper(root.left, count)
        rightUnival = self.__numberUnivalSubTreeHelper(root.right, count)
        if not leftUnival or not rightUnival:
            return False
        if root.left and root.left.val != root.val:
            return False
        if root.right and root.right.val != root.val:
            return False
        count[0] += 1
        return True


    def numberUnivalSubtreeRecursive(self, root):
        count = [0]
        self.__numberUnivalSubTreeHelper(root, count)
        return count[0]

    # Iterative method using postorder traversal and hashmap
    # Time complexity: O(n)
    # Space complexity: O(n)
    def numberUnivalSubtreeIterative(self, root):
        stack = []
        d = {}
        d[None] = True
        cur = root
        count = 0
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
                        d[node] = False
                        if not d[node.left] or not d[node.right]:
                            continue
                        if node.left and node.left.val != node.val:
                            continue
                        if node.right and node.right.val != node.val:
                            continue
                        d[node] = True
                        count += 1
                        continue
                    if stack and node.right and node.right == stack[-1]:
                        stack.pop()
                        cur = node.right
                        stack.append(node)
                else:
                    break
        return count

#    0
#   / \
#  1   0
#     / \
#    1   0
#   / \
#  1   1
a = Node(0)
a.left = Node(1)
a.right = Node(0)
a.right.left = Node(1)
a.right.right = Node(0)
a.right.left.left = Node(1)
a.right.left.right = Node(1)
print(a)
s = Solution()
print(s.numberUnivalSubtreeRecursive(a))
print(s.numberUnivalSubtreeIterative(a))
