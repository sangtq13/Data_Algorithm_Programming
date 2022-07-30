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

    # Recursive method:
    # Time complexity: O(n)
    # Space complexity: O(n) in worse case
    def ArithmeticRecursive(self, root):
        if not root:
            return 0
        operators = {
            '+': lambda a, b: a + b,
            '-': lambda a, b: a - b,
            '/': lambda a, b: a / b,
            '*': lambda a, b: a * b,
        }
        if root.val in operators:
            left_val = self.ArithmeticRecursive(root.left)
            right_val = self.ArithmeticRecursive(root.right)
            fn = operators[root.val]
            root.val = fn(left_val, right_val)
        return root.val

    # Using postorder traverse
    # Time complexity: O(n)
    # Space complexity: O(n)
    def ArithmeticBinaryTree(self, root):
        stack = []
        operators = {
            '+': lambda a, b: a + b,
            '-': lambda a, b: a - b,
            '/': lambda a, b: a / b,
            '*': lambda a, b: a * b,
        }
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
                    if not node.left and not node.right:
                        continue
                    if node.val in operators and node.left.val not in operators and node.right not in operators:
                        fn = operators[node.val]
                        node.val = fn(node.left.val, node.right.val)

                    if stack and node.right == stack[-1]:
                        stack.pop()
                        cur = node.right
                        stack.append(node)
                else:
                    break
        return root.val

#       *
#      / \
#     +   +
#    / \ / \
#   3  2 4  5
node = Node('*')
node.left = Node('+')
node.right = Node('+')
node.left.left = Node(3)
node.left.right = Node(2)
node.right.left = Node(4)
node.right.right = Node(5)
print(node)
s = Solution()
print(s.ArithmeticRecursive(node))
print(s.ArithmeticBinaryTree(node))
