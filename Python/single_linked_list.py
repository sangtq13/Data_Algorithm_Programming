class Node(object):
    def __init__(self, value, next=None):
        self.value = value
        self.next = next

    def __str__(self):
        curr = self
        output = ''
        while curr:
            output += str(curr.value)
            curr = curr.next
        return output

    def reverseLinkedList(self, head):
        cur = head
        pre = None
        while cur:
            pre = cur
            cur = cur.next
            if pre == head:
                pre.next = None
            else:
                pre.next = head
            head = pre

        return head

    def removeLinkedListEmelemt(self, head, value):
        if head.value == value:
            return head.next
        cur = head.next
        pre = head

        while cur:
            if cur.value == value:
                pre.next = cur.next
                del cur
                break
            pre = cur
            cur = cur.next

        return head

    def oddEvenLinkedList(self, head):
        if head == None:
            return head
        even = head
        odd = head.next
        firstOdd = odd

        while 1:
            if not even or not odd or not odd.next:
                even.next = firstOdd
                break
            even.next = odd.next
            even = odd.next

            if not even.next:
                odd.next = None
                even.next = firstOdd
                break
            odd.next = even.next
            odd = even.next

        return head

    def checkPalindrome(self, head):
        pre = head
        cur = head
        while cur.next and cur.next.next:
            pre = pre.next
            cur = cur.next.next

        suffix = self.reverseLinkedList(pre.next)

        while cur.next:
            if head.value != cur.value:
                return False
            break

        return True

n = Node(1, Node(2, Node(3, Node(4, Node(5)))))
print(n)
reverseList = n.reverseLinkedList(n)
print(reverseList)
print(reverseList.removeLinkedListEmelemt(reverseList, 3))
oddEvenList = reverseList.oddEvenLinkedList(reverseList)
print(oddEvenList)

p = Node(1, Node(2, Node(3, Node(2, Node(1)))))
print(p.checkPalindrome(p))

"""
Output:
12345
54321
5421
5241
True
"""
