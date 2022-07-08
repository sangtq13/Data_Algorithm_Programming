class Node(object):
    def __init__(self, val, next=None):
        self.val = val
        self.next = next

    def __repr__(self):
        result = ''
        head = self
        while head:
            result += str(head.val) + ' '
            head = head.next

        return result

class Solution():
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: O(n)
    # Space complexity: O(1)
    def rotateLinkedList(self, head, k):
        cur = head
        tail = None
        length = 0
        while cur:
            length += 1
            tail = cur
            cur = cur.next
        k = length - k % length - 1
        cur = head
        while k:
            cur = cur.next
            k -= 1
        tail.next = head
        head = cur.next
        cur.next = None

        return head

head = Node(1, Node(2, Node(3, Node(4, Node(5)))))
print(Solution().rotateLinkedList(head, 4))
