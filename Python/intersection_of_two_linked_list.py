class Node(object):
    def __init__(self, val, next=None):
        self.val = val
        self.next = next

    def __repr__(self):
        result = ''
        n = self
        while n:
            result += str(n.val) + ' '
            n = n.next

        return result

class Solution():
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: O(m+n)
    # Space complexity: O(1)
    def intersectionA(self, headA, headB):
        if not headA or not headB:
            return None
        la = lb = 0
        cur = headA
        while cur:
            la += 1
            cur = cur.next
        cur = headB
        while cur:
            lb += 1
            cur = cur.next
        if la > lb:
            diff = la - lb
            for i in range(diff):
                headA = headA.next
        if la < lb:
            diff = lb - la
            for i in range(diff):
                headB = headB.next

        while headA != headB:
            headA = headA.next
            headB = headB.next

        return headA

    # Using hashmap method
    # Time complexity: O(m+n)
    # Space complexity: O(m)
    def intersectionB(self, headA, headB):
        if not headA or not headB:
            return None
        d = {}
        while headA:
            d[headA] = True
            headA = headA.next
        while headB:
            if headB in d:
                return headB
            headB = headB.next

a = Node(1)
b = a
#a.next = Node(2)
#a.next.next = Node(3)
#a.next.next.next = Node(4)

#b = Node(6)
#b.next = a.next.next

print(a, b)
s = Solution()
print(s.intersectionA(a, b))
print(s.intersectionB(a, b))
