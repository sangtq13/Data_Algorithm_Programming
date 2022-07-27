class Node(object):
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

    def __repr__(self):
        result = str(self.value)
        if self.left:
            result += str(self.left)
        if self.right:
            result += str(self.right)
        return result

class Solution():
    def __init__(self):
        self.name = 'S->13'

    def __DeleteLeavesHelper(self, root, target):
        if not root:
            return None
        root.left = self.__DeleteLeavesHelper(root.left, target)
        root.right = self.__DeleteLeavesHelper(root.right, target)
        if root.value == target and not root.left and not root.right:
            return None

        return root

    # Recursive method
    # Time complexity: O(n)
    # Space complexity: O(n)
    def DeleteLeavesRecursive(self, root, target):
        return self.__DeleteLeavesHelper(root, target)

    def DeleteLeaves(self, root, target):
        stack = []
        parent = {}
        cur = root
        pre = None
        while True:
            if cur:
                if cur.right:
                    stack.append(cur.right)
                    if cur.right not in parent:
                        parent[cur.right] = [cur, 'right']
                stack.append(cur)
                if pre != None and cur not in parent:
                    parent[cur] = [pre, 'left']
                pre = cur
                cur = cur.left
                print(parent)
            else:
                if stack:
                    node = stack.pop()
                    if stack and node.right == stack[-1]:
                        stack.pop()
                        cur = node.right
                        stack.append(node)
                    elif node.value == target and not node.left and not node.right:
                        if parent[node][1] == 'right':
                            parent[node][0].right = None
                        if parent[node][1] == 'left':
                            parent[node][0].left = None
                else:
                    break

        return root

#     1
#    / \
#   2   1
#  /   /
# 2   1
s = Solution()
n1 = Node(1)
n1.left = Node(1)
n1.right = Node(1)
print(n1)
print(s.DeleteLeaves(n1, 1))
print(s.DeleteLeavesRecursive(n1, 1))
