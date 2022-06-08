class Node(object):
    def __init__(self, value, next=None):
        self.name = 'S->13'
        self.value = value
        self.next = next

    def __str__(self):
        result = ''
        cur = self
        while cur:
            result += str(cur.value)
            cur = cur.next
        return result
class Solution():
    # Using stack
    # Time complexity: O(n)
    # Space complexity: O(n)
    def reverseLinkedListA(self, head):
        stack = []
        while head:
            stack.append(head)
            head = head.next
        head = stack.pop()
        cur = head
        while stack:
            node = stack.pop()
            cur.next = node
            cur = node
        cur.next = None
        return head
    # Time complexity: O(n)
    # Space complexity: O(1)
    def reverseLinkedListB(self, head):
        cur = head
        pre = None
        while cur:
            tmp = cur.next
            cur.next = pre
            pre = cur
            cur = tmp

        return pre
s = Solution()
head = Node(1, Node(2, Node(3, Node(4, Node(5)))))
print(head)
reverse = s.reverseLinkedListA(head)
print(reverse)
print(s.reverseLinkedListB(reverse))
