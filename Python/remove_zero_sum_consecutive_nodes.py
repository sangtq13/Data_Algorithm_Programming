from collections import OrderedDict
class Node(object):
    def __init__(self, val, next=None):
        self.val = val
        self.next = next

    def __str__(self):
        result = ''
        cur = self
        while cur:
            result += str(cur.val)
            cur = cur.next
        return result

    # For python 3, dictionary popitem will remove the last key inserting
    # to dict. For python 2, popitem will remove any pair (key, value)
    # in dict. So for python 2 we need to use OrderDict
    # Time complexity: O(n)
    # Space complexity: O(n)
    def removeZeroSumConsecutiveNodes(self, head):
        d = {}
        sum = 0
        dummy = Node(0)
        dummy.next = head
        head = dummy
        cur = dummy
        while cur:
            sum += cur.val
            if sum in d:
                d[sum].next = cur.next
                tmp = d[sum]
                while d:
                    if d.popitem()[0] == sum:
                        break
                d[sum] = tmp
            else:
                d[sum] = cur
            cur = cur.next
        return head.next

    # Time complexity: O(n)
    # Space complexity: O(n)
    def removeZeroSumConsecutiveNodesB(self, head):
        d = OrderedDict()
        sum = 0
        dummy = Node(0)
        dummy.next = head
        head = dummy
        cur = dummy
        while cur:
            sum += cur.val
            if sum in d:
                d[sum].next = cur.next
                tmp = d[sum]
                while d:
                    if d.popitem()[0] == sum:
                        break
                d[sum] = tmp
            else:
                d[sum] = cur
            cur = cur.next
        return head.next
# head = Node(3, Node(-3, Node(2, Node(-2, Node(-1, Node(4, Node(1, None)))))))
head = Node(1, Node(2, Node(3, Node(-3, Node(-2, None)))))
# print(head)
# print(head.removeZeroSumConsecutiveNodes(head))
print(head.removeZeroSumConsecutiveNodesB(head))
