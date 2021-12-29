/*
Definition for singly-linked list
function ListNode(val, next) {
    this.val = (val === undefined ? 0 : val)
    this.next = (next === undefined ? null : next)
}
*/

var middleNode = (head) => {
    let slow = head, fast = head
    while(fast) {
        if (fast.next && fast.next.next) {
            slow = slow.next
            fast = fast.next.next
        }
        else{
            if(fast.next === null) return slow
            else return slow.next
        }
    }
}