import heapq
class Node(object):
    def __init__(self, val, next=None):
        self.val = val
        self.next = next

    def __repr__(self):
        n = self
        result = ''
        while n:
            result += str(n.val) + ' '
            n = n.next

        return result

class Solution():
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: O(k*n) with k is the len of lists
    # Space complexity: O(1)
    def mergeKSortedLinkedList(self, lists):
        head = cur = Node(-1)
        while lists:
            minVal, minIdx = 10001, -1
            for i, n in enumerate(lists):
                if n and n.val < minVal:
                    minIdx = i
                    minVal = n.val
            if minIdx == -1:
                return head.next
            cur.next = lists[minIdx]
            cur = lists[minIdx]
            if lists[minIdx].next != None:
                lists[minIdx] = lists[minIdx].next
            else:
                lists.pop(minIdx)

        return head.next
    
    # This method using heap data structure to increase performance
    # Time complexity: O(n)
    # Space complexity: O(n)
    def mergeKSortedLinkedListB(self, lists):
        head = cur = Node(-1)
        heap = []
        for i, n in enumerate(lists):
            heap.append((n.val, i))
        if not heap:
            return None
        heapq.heapify(heap)
        while heap:
            minVal, minIdx = heapq.heappop(heap)
            cur.next = lists[minIdx]
            cur = lists[minIdx]
            if lists[minIdx].next != None:
                lists[minIdx] = lists[minIdx].next
                heap.append((lists[minIdx].val, minIdx))
                heapq.heapify(heap)

        return head.next

a = Node(1, Node(3, Node(7, Node(8))))
b = Node(2, Node(3, Node(4, Node(6, Node(9)))))
c = Node(3, Node(3, Node(4, Node(8, Node(11)))))
d = Node(5, Node(6, Node(7, Node(8, Node(11, Node(12, Node(13)))))))
lists = [a, b, c, d]
s = Solution()
print(s.mergeKSortedLinkedListB(lists))
