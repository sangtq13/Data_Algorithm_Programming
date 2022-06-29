from collections import deque
class Node(object):
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def __repr__(self):
        root = self
        result = ''
        q = deque()
        q.append(root)
        while q:
            node = q.popleft()
            result += str(node.val) + ' '
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)
        return result


class Codec(object):
    def __init__(self):
        self.name = 'S->13'

    # Using BFS to serial lize data to string, * for None pointer
    # Time complexity: O(n)
    # Space complexity: O(n)
    def serialize(self, root):
        q = deque()
        q.append(root)
        result = ''

        while q:
            node = q.popleft()
            if not node:
                result += '*.'
                continue
            else:
                result += str(node.val) + '.'
            q.append(node.left)
            q.append(node.right)
        return result[:-1]

    # Using queue to decode from string
    # Time complexity: O(n)
    # Space complexity: O(n)
    def deserialize(self, data):
        n = data.split('.')
        if n[0] == '*':
            return None

        root = Node(int(n[0]))
        q = deque()
        q.append(root)
        for i in range(1, len(n), 2):
            node = q.popleft()
            if n[i] != '*':
                node.left = Node(int(n[i]))
                q.append(node.left)
            if n[i+1] != '*':
                node.right = Node(int(n[i+1]))
                q.append(node.right)

        return root

    # Using preorder traversal
    # Time complexity: O(n)
    # Space complexity: O(n)
    def serializeA(self, root):
        if not root: return '*'
        return str(root.val) + '.' + self.serializeA(root.left) + '.' + self.serializeA(root.right)

    # Using DFS to convert string to Tree
    # Time complexity: O(n)
    # Space complexity: O(n)
    def deserializeA(self, data):
        l = data.split('.')
        if l[0] == '*': return None
        stack = []
        root = Node(int(l[0]))
        cur = root
        i = 1
        while True:
            if cur:
                stack.append(cur)
                if l[i] != '*':
                    cur.left = Node(int(l[i]))
                cur = cur.left
            else:
                if stack:
                    node = stack.pop()
                    if l[i] != '*':
                        node.right = Node(int(l[i]))
                        cur = node.right
                else:
                    break
            i += 1
        return root

root = Node(1, Node(2, Node(4), Node(5)), Node(3, Node(6), Node(7)))
print(root)
data = Codec().serialize(root)
print(data)
print(Codec().deserialize(data))

data = Codec().serializeA(root)
print(data)
# 1.2.3.4.5.6.7.*.*.*.*.*.*.*.*.
print(Codec().deserializeA(data))
# 1 2 3 4 5 6 7
