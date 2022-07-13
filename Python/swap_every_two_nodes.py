class Node(object):
    def __init__(self, val, next=None):
        self.val = val
        self.next = next

    def __repr__(self):
        result = ''
        cur = self
        while cur:
            result += str(cur.val) + ' '
            cur = cur.next
        return result

class Solution():
    def __init__(self):
        self.name = 'S->13'

    # Swap value method
    # Time complexity: O(n)
    # Space complexity: O(n)
    def SwapEveryTwoNodes1(self, head):
        cur = head
        while cur and cur.next:
            cur.val, cur.next.val = cur.next.val, cur.val
            cur = cur.next.next
        return head

    # Using linking method
    # Time complexity: O(n)
    # Space complexity: O(1)
    def SwapEveryTwoNodes2(self, head):
        cur = head
        tail = None
        while cur and cur.next:
            if (tail == None):
                head = cur.next
            else :
                tail.next = cur.next
            tmp = cur.next.next
            cur.next.next = cur
            tail = cur
            cur = tmp
        if tail: tail.next = cur
        return head

head = Node(1, Node(2, Node(3, Node(4, Node(5, Node(6, Node(7)))))))
print(head)
s = Solution()
print(s.SwapEveryTwoNodes1(head))
print(s.SwapEveryTwoNodes2(head))
