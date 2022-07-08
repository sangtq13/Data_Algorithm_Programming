function Node(val, left, right) {
    this.val = (val===undefined ? 0 : val)
    this.left = (left===undefined ? null : left)
    this.right = (right===undefined ? null : right)
}

var inorder_successor_helper = (root, ret ,value) => {
    if (!root) {
        return [null, null];
    }
    if (root.val > value) {
        ret = root
        return inorder_successor_helper(root.left, ret, value)
    }
    else if (root.val < value) {
        return inorder_successor_helper(root.right, ret, value)
    }
    else {
        return [ret, root.right]
    }
}

// Recursive method 
// Time complexity: O(n) in worst case
// Space complexity: O(n) in worst case
var inorder_successor_recursive = (root,value) => {
    var arr = inorder_successor_helper(root, null, value)
    if (arr[1]) {
        var pre = null
        var cur = arr[1]
        while (cur) {
            pre = cur
            cur = cur.left
        }
        return pre
    }
    return arr[0]
}


// Using search in BST
// Time complexity: O(n) in worst case
// Space complexity: O(1)
var inorder_successor_a = (root, value) => {
    var cur = root
    var ret = null

    while (true) {
        if (cur.val > value) {
            ret = cur
            cur = cur.left
        }
        else if (cur.val < value) {
            cur = cur.right
        }
        else {
            if (cur.right) {
                cur = cur.right
                var pre = cur
                while (cur) {
                    pre = cur
                    cur = cur.left
                }
                return pre
            }
            else {
                return ret
            }
        }
    }

    return null
 }

 // Using inorder traversal method
 // Time complexity: O(n)
 // Space complexity: O(n)
var inorder_successor_b = (root, value) => {
    var cur = root
    var ret = null
    var found = false
    stack = []

    while (true) {
        if (cur) {
            stack.push(cur)
            cur = cur.left
        }
        else {
            if (stack) {
                var node = stack.pop()
                if (node.val > value && found) {
                    return node
                }
                if (node.val == value) {
                    found = true
                }
                if (node.right) {
                    cur = node.right
                }
            }
        }
    }

    return null
}

//     4
//    / \
//   2   8
//  /   / \
// 1   5   9
//      \
//       7

root = new Node(4)
root.left = new Node(2)
root.right = new Node(8)
root.left.left = new Node(1)
root.right.left = new Node(5)
root.right.right = new Node(9)
root.right.left.right = new Node(7)
console.log(inorder_successor_recursive(root, 4))
console.log(inorder_successor_recursive(root, 8))
console.log(inorder_successor_recursive(root, 7))
console.log(inorder_successor_recursive(root, 1))

console.log(inorder_successor_a(root, 4))
console.log(inorder_successor_a(root, 8))
console.log(inorder_successor_a(root, 7))
console.log(inorder_successor_a(root, 1))

console.log(inorder_successor_b(root, 4))
console.log(inorder_successor_b(root, 8))
console.log(inorder_successor_b(root, 7))
console.log(inorder_successor_b(root, 1))
