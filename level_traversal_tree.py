
class Node(object):
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

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
                    if stack and node.right == stack[-1]:
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

    # Recursive method:
    # Time complexity: O(n)
    # Space complexity: O(n)
    def __levelTraversalHelper(self, root, height, result):
        if not root: return
        if height > len(result):
            result.append([root.val])
        else:
            result[height-1].append(root.val)
        self.__levelTraversalHelper(root.left, height + 1, result)
        self.__levelTraversalHelper(root.right, height + 1, result)

    def levelTraversalRecursive(self, root):
        result = []
        self.__levelTraversalHelper(root, 1, result)
        return result
    # Iterative method using BFS
    # Time complexity: O(n)
    # Space complexity: O(n)
    def levelTraversalBFS(self, root):
        if not root: return []
        maxHeight = 0
        q = deque()
        q.append((root, 1))
        ret = []
        while q:
            node, height = q.popleft()
            if height > maxHeight:
                maxHeight = height
                ret.append([node.val])
            else:
                ret[-1].append(node.val)
            if node.left:
                q.append((node.left, height+1))
            if node.right:
                q.append((node.right, height+1))

        return ret

    # Iterative method using DFS
    # Time complexity: O(n)
    # Space compexlity: O(n)
    def levelTraversalDFS(self, root):
        ret = []
        stack = [(root,1)]
        while stack:
            node, height = stack.pop()
            if height > len(ret):
                ret.append([node.val])
            else:
                ret[height-1].append(node.val)
            if node.right:
                stack.append((node.right, height + 1))
            if node.left:
                stack.append((node.left, height + 1))

        return ret
#           1
#          / \
#         2   4
#        /   / \
#       3   5   6
#      /   /
#     8   7
root = Node(1, Node(2, Node(3, Node(8))), Node(4, Node(5, Node(7)), Node(6)))
print(root)
print(Solution().levelTraversalDFS(root))
print(Solution().levelTraversalBFS(root))
print(Solution().levelTraversalRecursive(root))
