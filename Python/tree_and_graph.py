from queue import deque
class Node(object):
    def __init__(self, value, children=[]):
        self.value = value
        self.children = children

    def dfs(self):
        print(self.value, end='')

        for child in self.children:
            child.dfs()

    def dfsIterative(self):
        stack = [self]
        while stack:
            node = stack.pop()
            print(node.value, end='')
            for child in reversed(node.children):
                stack.append(child)

    def bfsIterative(self):
        queue = deque([self])

        while queue:
            node = queue.popleft()
            print(node.value, end='')
            for child in self.children:
                queue.append(child)
    # def preorder(self):
    #
    # def inorder(self):

    def postorder(self):
        for child in self.children:
            child.postorder()

        print(self.value, end='')
#     a
#    / \
#   b   c
#  / \   \
# d   e   f

root = Node('a', [Node('b', [Node('d'), Node('e')]), Node('c', [Node('f')])])

root.dfs()
# abdecf
print("")

root.postorder()
# debfca
print("")

root.dfsIterative()
# abdecf
print("")

root.bfsIterative()
abcdef
