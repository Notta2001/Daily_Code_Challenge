/*
Definition for singly-linked list 
function ListNode(val, next) {
    this.val = (val===undefined ? 0 : val);
    this.next = (next===undefined ? null : next);
}
*/

const removeNthFromEnd = (head, n) => {
    let i = head;
    let k = head;
    let prev = null;
    let diff = 0;
    while (i) {
        i = i.next;
        diff ++;
        if (diff > n) {
            prev = k;
            k = k.next;
        };
    };
    if (diff === n) {
        head = head.next;
        return head;
    };
    if (prev) {
        prev.next = prev.next ?.next || null;
        return head;
    };
    return null;
};

//https://leetcode.com/problems/remove-nth-node-from-end-of-list/submissions/