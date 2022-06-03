class Node(object):
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

    def preOrder(self, root):
        if not root:
            return
        print(root.value, end='')
        self.preOrder(root.left)
        self.preOrder(root.right)

    def preOrderIterative(selfs, root):
        stack = [root]

        while stack:
            node = stack.pop()
            print(node.value, end='')
            if node.right:
                stack.append(node.right)
            if node.left:
                stack.append(node.left)



    def inOrder(self, root):
        if not root:
            return
        self.inOrder(root.left)
        print(root.value, end='')
        self.inOrder(root.right)

    def inOrderIterative(self, root):
        stack = []
        cur = root
        while 1:
            if cur:
                stack.append(cur)
                cur = cur.left
            else:
                if stack:
                    node = stack.pop()
                    print(node.value, end='')
                    if node.right:
                        cur = node.right
                else:
                    break

    def postOrder(self, root):
        if not root:
            return
        self.postOrder(root.left)
        self.postOrder(root.right)
        print(root.value, end='')

    def postOrderIterative(self, root):
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
                    if stack and node.right and node.right == stack[-1]:
                        stack.pop()
                        cur = node.right
                        stack.append(node)
                    else:
                        print(node.value, end='')

                else:
                    break

    def search(self, root, value):
        if not root or root.value == value:
            return root
        if root.value > value:
            return self.search(root.left, value)
        if root.value < value:
            return self.search(root.right, value)

    def searchIterative(self, root, value):
        cur = root
        while cur:
            if cur.value > value:
                cur = cur.left
            elif cur.value == value:
                return cur
            else:
                cur = cur.right

        return None

    def insert(self, root, value):
        if not root:
            return Node(value)
        if root.value == value:
            return root
        elif root.value > value:
            root.left = self.insert(root.left, value)
        else:
            root.right = self.insert(root.right, value)
        return root

    def __minValue(self, root):
        if not root:
            return root
        cur = root
        while cur.left:
            cur = cur.left
        return cur

    def delete(self, root, value):
        if not root:
            return root
        if root.value > value:
            root.left = self.delete(root.left, value)
        elif root.value < value:
            root.right = self.delete(root.right, value)
        else:
            if not root.left:
                return root.right
            if not root.right:
                return root.left
            minRightNode = self.__minValue(root.right)
            root.value = minRightNode.value
            root.right = self.delete(root.right, minRightNode.value)

        return root

def binarySearch(arr, low, high, value):
    if high < low:
        return -1
    mid = (low+high)//2
    if value == arr[mid]:
        return mid
    elif value > arr[mid]:
        return binarySearch(arr, mid+1, high, value)
    else:
        return binarySearch(arr, low, mid-1, value)

def binarySearchIterative(arr, low, high, value):
    while low <= high:
        mid = (low+high)//2
        if arr[mid] == value:
            return mid
        elif arr[mid] > value:
            high = mid-1
        else:
            low = mid+1
    return -1


class KthLargest(object):
    def __init__(self, k, arr=[]):
        self.k = k
        self.size = len(arr)
        if (len(arr)>0):
            self.root = Node(arr[0])
        for i in range(1, len(arr)):
            self.root = self.root.insert(self.root, arr[i])

    def __kthLargest(self):
        stack = []
        count = 0
        cur = self.root
        while True:
            if cur:
                stack.append(cur)
                cur = cur.left
            else:
                if stack:
                    node = stack.pop()
                    count += 1
                    if count == self.size-self.k+1:
                        return node.value
                    cur = node.right

        return -1

    def add(self, value):
        self.root = self.root.insert(self.root, value)
        # self.root.inOrder(self.root)
        # print("")
        self.size += 1
        return self.__kthLargest()

#          4
#         / \
#        2   6
#       / \   \
#      1   3   7


root = Node(4, Node(2, Node(1), Node(3)), Node(6, None, Node(7)))
# root.preOrder(root)
# print("")
# root.preOrderIterative(root)
# print("")
# root.inOrder(root)
# print("")
# root.inOrderIterative(root)
# print("")
# root.postOrder(root)
# print("")
# root.postOrderIterative(root)
# print("")
# root.insert(root, 5)
# root.preOrder(root)
# print("")
#searchNode = root.search(root, 2)
searchNode = root.searchIterative(root, 2)
searchNode.inOrder(searchNode)
print("")
arr = [1,2,3,4,5,6,7]
print(binarySearch(arr, 0, len(arr)-1, 5))
print(binarySearchIterative(arr, 0, len(arr)-1, 5))
#
# root.delete(root, 6)
# root.inOrder(root)

# kthLargest = KthLargest(3, [1,2,5,4,3,6,7])
# kthLargest.root.inOrder(kthLargest.root)
# print("")
# print(kthLargest.add(8))
# print(kthLargest.add(9))
# print(kthLargest.add(10))
