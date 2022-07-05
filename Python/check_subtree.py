class Node(object):
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def __repr__(self):
        cur = self
        result = ''
        stack = []
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

    def __compare(self, r1, r2):
        if not r1 and not r2: return True
        if not r1 or not r2 or r1.val != r2.val: return False
        return self.__compare(r1.left, r2.left) and self.__compare(r1.right, r2.right)

    def __getLength(self, root):
        length = 0
        stack = [root]
        while stack:
            node = stack.pop()
            length += 1
            if node.left: stack.append(node.left)
            if node.right: stack.append(node.right)
        return length

    # This method using postorder method to determine the
    # length of each node in tree. If length of node equals to
    # length of sub tree, We compare to tree to check similarly.
    # Time complexity: O(n)
    # Space complexity: O(n)
    def checkSubtreeA(self, root, subRoot):
        cur = root
        stack = []
        subLength = self.__getLength(subRoot)
        length = {None: 0}
        while True:
            if cur:
                if cur.right:
                    stack.append(cur.right)
                stack.append(cur)
                cur = cur.left
            else:
                if stack:
                    node = stack.pop()
                    if node.left in length and node.right in length:
                        length[node] = length[node.left] + length[node.right] + 1
                        if length[node] == subLength and self.__compare(node, subRoot):
                            return True
                    if stack and node.right and node.right == stack[-1]:
                        stack.pop()
                        cur = node.right
                        stack.append(node)
                else:
                    break
        return False

    def __serialize(self, root):
        if not root: return '*'
        return str(root.val) + '.' + self.__serialize(root.left) + '.' + self.__serialize(root.right)

    def checkSubtreeB(self, root, subRoot):
        subStr = self.__serialize(subRoot)
        rootStr = self.__serialize(root)
        return subStr in rootStr

n = Node(1)
n.left = Node(4)
n.right = Node(5)
n.left.left = Node(3)
n.left.right = Node(2)
n.right.left = Node(4)
n.right.right = Node(1)
# n.left.left.left = Node(3)

b = Node(4)
b.left = Node(3)
b.right = Node(2)
# print(b)

s = Solution()
print(s.checkSubtreeA(n, b))

print(s.checkSubtreeB(n, b))
