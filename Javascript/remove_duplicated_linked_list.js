function Node(val, next) {
    this.val = val === undefined ? 0 : val
    this.next = next === undefined ? null : next
}

var PrintNode = function (head) {
    result = ''
    cur = head
    while (cur) {
        result += cur.val + ' '
        cur = cur.next
    }
    return result
}

// Time complexity: O(n)
// Space complexity: O(n)
var RemoveDuplicated = (head) => {
    var d = {}
    var cur = head
    var pre = null
    
    while (cur) {
        if (cur.val in d) {
            pre.next = cur.next 
        }
        else {
            d[cur.val] = 1
        }
        pre = cur
        cur = cur.next
    }

    return head
}

head = new Node(1)
head.next = new Node(2)
head.next.next = new Node(2)
head.next.next.next = new Node(3)
head.next.next.next.next = new Node(4)

console.log(PrintNode(head))
console.log(PrintNode(RemoveDuplicated(head)))
