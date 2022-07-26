from collections import deque
class Node(object):
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def __repr__(self):
        result = str(self.val)
        if self.left:
            result += str(self.left)
        if self.right:
            result += str(self.right)

        return result

class Solution():
    def __init__(self):
        self.name = 'S->13'

    def __ZigzagHelper(self, root, height, result):
        if not root:
            return
        if height > len(result) :
            result.append([root.val])
        else:
            result[height-1].append(root.val)
        if root.left:
            self.__ZigzagHelper(root.left, height + 1, result)
        if root.right:
            self.__ZigzagHelper(root.right, height + 1, result)

    # Recursive function
    # Time complexity: O(n)
    # Space complexity: O(n)
    def ZigzagBinaryTree(self, root):
        result = []
        self.__ZigzagHelper(root, 1, result)
        for i in range(len(result)):
            if i % 2 == 0:
                result[i] = result[i][::-1]

        return result

    # Iterative method using BFS and reverse
    # Time complexity: O(n)
    # Space complexity: O(n)
    def ZigzagIterative1(self, root):
        if not root:
            return []
        q = deque()
        q.append((root, 1))
        result = []

        while q:
            node, height = q.popleft()
            if height > len(result):
                if height % 2 == 0:
                    result[-1] = result[-1][::-1]
                result.append([node.val])

            else:
                result[height-1].append(node.val)

            if node.left:
                q.append((node.left, height + 1))
            if node.right:
                q.append((node.right, height + 1))

        return result

    # Using 2 stacks method
    # Time complexity: O(n)
    # Space complexity: O(n)
    def ZigzagIterative2(self, root):
        cur_stack = [root]
        next_stack = []
        result = []
        current_level = 1
        left_to_right = False
        while cur_stack:
            node = cur_stack.pop()
            if current_level > len(result):
                result.append([node.val])
            else:
                result[-1].append(node.val)
            if left_to_right:
                if node.left:
                    next_stack.append(node.left)
                if node.right:
                    next_stack.append(node.right)
            else:
                if node.right:
                    next_stack.append(node.right)
                if node.left:
                    next_stack.append(node.left)
            if len(cur_stack) == 0:
                left_to_right = not left_to_right
                cur_stack, next_stack = next_stack, cur_stack
                current_level += 1

        return result

#             1
#          /     \
#         2       3
#       /  \    /   \
#      4    5  6     7
#     /             /
#    9             8
root = Node(1, Node(2, Node(4, Node(9)), Node(5)), Node(3, Node(6), Node(7, Node(8))))
print(root)
s = Solution()
print(s.ZigzagBinaryTree(root))
print(s.ZigzagIterative1(root))
print(s.ZigzagIterative2(root))
#123765498
