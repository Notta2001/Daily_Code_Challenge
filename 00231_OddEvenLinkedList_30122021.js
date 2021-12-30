var oddEvenList = (head) => {
    if(!head) {
        return head
    }
    let odd = head
    let even = head.next
    let evenHead = even

    while (even !== null && even.next !== null) {
        odd.next = odd.next.next
        even.next = even.next.next
        odd = odd.next
        even = even.next
    }
    odd.next = evenHead

    return head
}