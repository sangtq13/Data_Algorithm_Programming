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

class Solution():
    def __init__(self):
        self.name = 'S->13'

    def __MostFrequentHelper(self, root, count, max_count):
        if not root:
            return 0
        left_sum = self.__MostFrequentHelper(root.left, count, max_count)
        right_sum = self.__MostFrequentHelper(root.right, count, max_count)
        root_sum = root.val + left_sum + right_sum
        count[root_sum] = count.get(root_sum, 0) + 1
        if count[root_sum] > max_count[0]:
            max_count[0] = count[root_sum]
        return root_sum

    # Recursive method
    # Time complexity: O(n)
    # Space complexity: O(n)
    def MostFrequentRecursive(self, root):
        max_count = [0]
        count = {}
        self.__MostFrequentHelper(root, count, max_count)
        return [k for k in count.keys() if count[k] == max_count[0]]
    
    # Using postorder traverse
    # Time complexity: O(n)
    # Space complexity: O(n)
    def MostFrequentSubtreeSum(self, root):
        max_count = 0
        d ={}
        count = {}
        d[None] = 0
        stack = []
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
                    if node.left in d and node.right in d:
                        d[node] = node.val + d[node.left] + d[node.right]
                        count[d[node]] = count.get(d[node], 0) + 1
                        if count[d[node]] > max_count:
                            max_count = count[d[node]]
                        continue
                    if stack and node.right and node.right == stack[-1]:
                        stack.pop()
                        cur = node.right
                        stack.append(node)
                else:
                    break

        return [k for k in count.keys() if count[k] == max_count]

root = Node(3, Node(1), Node(-3))
s = Solution()
print(s.MostFrequentSubtreeSum(root))
print(s.MostFrequentRecursive(root))
