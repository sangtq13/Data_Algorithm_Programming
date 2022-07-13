function Node(val, next) {
    this.val = val === undefined ? 0 : val
    this.next = next === undefined ? null : next
}

// Using swap method
// Time complexity: O(n)
// Space complexity: O(1)
var SwapNodes1 = (head) => {
    var cur = head
    while (cur && cur.next) {
        [cur.val, cur.next.val] = [cur.next.val, cur.val]
        cur = cur.next.next
    }
    return head
}

// Using linking method
// Time complexity: O(n)
// Space complexity: O(1)
var SwapNodes2 = (head) => {
    cur = head
    tail = null
    while (cur && cur.next) {
        if (!tail) {
            head = cur.next
        }
        else {
            tail.next = cur.next
        }
        var tmp = cur.next.next
        cur.next.next = cur
        tail = cur
        cur = tmp
    }
    if (tail) tail.next = cur

    return head
}

head = new Node(1)
head.next = new Node(2)
head.next.next = new Node(3)
head.next.next.next = new Node(4)
console.log(head)
console.log(SwapNodes1(head))
console.log(SwapNodes2(head))
