function Node(val, next) {
    this.val = (val===undefined ? 0 : val)
    this.next = (next===undefined ? null : right)
}
// Time complexity: O(n)
// Space complexity: O(1)
var rotateLinkedList = (head, k) => {
    var len = 0
    var cur = head
    var tail = null
    while (cur) {
        len++
        tail = cur
        cur = cur.next
    }
    k = len - k % len - 1
    cur = head
    while (k) {
        cur = cur.next
        k--
    }
    tail.next = head
    head = cur.next
    cur.next = null
    return head
}

head = new Node(1)
head.next = new Node(2)
head.next.next = new Node(3)
head.next.next.next = new Node(4)
head.next.next.next.next = new Node(5)

console.log(rotateLinkedList(head, 1))
