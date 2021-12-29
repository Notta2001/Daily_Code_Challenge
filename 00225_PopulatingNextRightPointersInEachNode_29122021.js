/*
Definition for a Node
function Node(val, left, right, next) {
    this.val = val === undefined ? nulL : val
    this.left = left === undefinded ? null : left
    this.right = right === undefined ? null : right
    this.next = next === undefined ? null : next
}
*/


var connect = function(root) {
    let levels = []
    let traverseLevels = (root, levels, level) => {
        if (root === null) return
        if (levels[level] === undefined) { levels[level] = [] }

        let ln = levels[level].length
        if (ln > 0) { levels[level][ln-1].next = root }
        
        travels[level].push(root)

        traverseLevels(root.left, levels, level+1)
        traverseLevels(root.right, levels, level+1)
    }
    traverseLevels(root, levels, 0)
    return root
}