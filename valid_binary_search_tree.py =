class Node(object):
    minValue = float('-inf')
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right
        self.low = float('-inf')
        self.high = float('inf')


    def __isValidBSTHelper(self, root, minValue, maxValue):
        if not root:
            return True
        if root.value <= minValue or root.value >= maxValue:
            return False
        return self.__isValidBSTHelper(root.left, minValue, root.value) and self.__isValidBSTHelper(root.right, root.value, maxValue)

    # isValidBST Recursion method: Using lower bound and
    # upper bound for each node to check
    # Time complexity: O(n)
    # Space complexity: O(1) without the size of stack else O(log n)
    def isValidBST(self, root):
        minValue = float('-inf')
        maxValue = float('inf')
        return self.__isValidBSTHelper(root, minValue, maxValue)

    # isValidBSTIterative method:
    # Time complexity: O(n)
    # Space complexity: O(n) for using stack
    def isValidBSTIterative(self, root):
        stack = [root]
        while stack:
            node = stack.pop()
            if node.value <= node.low or node.value >= node.high:
                return False
            if node.left:
                node.left.low = node.low
                node.left.high = node.value
                stack.append(node.left)
            if node.right:
                node.right.low = node.value
                node.right.high = node.high
                stack.append(node.right)

        return True
    # isValidBSTInorder method:
    # Time complexity: O(n)
    # Space complexity: O(1) without the size of stack else O(log n)
    def isValidBSTInorder(self, root):
        if not root:
            return True
        if not self.isValidBSTInorder(root.left):
            return False
        if root.value <= Node.minValue:
            return False
        else:
            Node.minValue = root.value

        return self.isValidBSTInorder(root.right)

    # isValidBSTIterative method
    # Using inorder traverse and check ascending order
    # Time complexity: O(n)
    # Space complexity: O(n) for using stack
    def isValidBSTInorderIterative(self, root):
        cur = root
        stack = []
        minValue = float('-inf')
        while True:
            if cur:
                stack.append(cur)
                cur = cur.left
            else:
                if stack:
                    node = stack.pop()
                    if node.value <= minValue:
                        return False
                    else:
                        minValue = node.value
                    if node.right:
                        cur = node.right
                else:
                    break

        return True

root = Node(4, Node(2, Node(1), Node(3)), Node(6, None, Node(7)))
# root = Node(4, Node(2, Node(1), Node(3)), Node(6, Node(8), Node(7)))
print(root.isValidBST(root))
print(root.isValidBSTIterative(root))
print(root.isValidBSTInorder(root))
print(root.isValidBSTInorderIterative(root))
