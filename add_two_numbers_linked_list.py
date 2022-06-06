class Node:
    def __init__(self, value, next=None):
        self.value = value
        self.next = next

    def __str__(self):
        root = self
        result = ''
        while root:
            result += str(root.value)
            root = root.next
        return result

class Solution(object):
    def __addTwoNumbersRecursive(self, l1, l2, carry):
        if not l1 and not l2:
            return None
        if not l1:
            l1 = Node(0)
        if not l2:
            l2 = Node(0)
        newCarry = (l1.value + l2.value + carry) // 10
        value = (l1.value + l2.value + carry) % 10
        root = Node(value)
        root.next = self.__addTwoNumbersRecursive(l1.next, l2.next, newCarry)

        return root
    # addTwoNumbersRecursive method
    # Time complexity: O(n)
    # Space complexity: O(n)
    def addTwoNumbersRecursive(self, l1, l2):
        return self.__addTwoNumbersRecursive(l1, l2, 0)

    # addTwoNumbersIterative method
    # Time Complexity: O(n)
    # Space complexity: O(n)
    def addTwoNumbersIterative(self, l1, l2):
        if not l1 and not l2:
            return None
        if not l1:
            l1 = Node(0)
        if not l2:
            l2 = Node(0)
        value = (l1.value + l2.value) % 10
        carry = (l1.value + l2.value) // 10
        root = Node(value)
        cur = root
        l1 = l1.next
        l2 = l2.next
        while l1 or l2:
            if not l1:
                l1 = Node(0)
            if not l2:
                l2 = Node(0)
            value = (l1.value + l2.value + carry) % 10
            carry = (l1.value + l2.value + carry) // 10
            cur.next = Node(value)
            cur = cur.next
            l1 = l1.next
            l2 = l2.next

        return root

l1 = Node(2)
l1.next = Node(4)
l1.next.next = Node(3)

l2 = Node(5)
l2.next = Node(6)
l2.next.next = Node(4)
l2.next.next.next = Node(6)

print(Solution().addTwoNumbersRecursive(l1, l2))
print(Solution().addTwoNumbersIterative(l1, l2))
