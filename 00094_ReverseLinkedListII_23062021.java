class ListNode{
	int val;
	ListNode next;
	
	ListNode(){
		
	}
	
	ListNode(int val){
		this.val = val;
	}
	
	ListNode(int val, ListNode next){
		this.val = val;
		this.next = next;
	}
}

public class ReverseLinkedListII {
	public static ListNode reverseBetween(ListNode head, int m, int n) {
		if (head == null) {
            return head;
        }
        ListNode fakeHead = new ListNode(-1);
        fakeHead.next = head;
        ListNode mp = fakeHead;
        for (int i = 0; i < m - 1; i ++) {
            mp = mp.next;
        }
        //mp.next is the first element to be reversed
        ListNode rhead = mp;
        mp = mp.next;
        ListNode rtail = mp;
        ListNode next = null;
        for (int i = 0; i < n - m + 1; i ++) {
            next = mp.next;
            mp.next = rhead.next;
            rhead.next = mp;
            mp = next;
        }
        rtail.next = mp;
        return fakeHead.next;
	}
	
	public static void printList(ListNode head) {
		while(head != null) {
			System.out.print(head.val);
			if(head.next != null) {
				System.out.print(" -> ");
			}
			head = head.next;
		}
	}
	
	public static void main(String[] args) {
		ListNode a1 = new ListNode (5);
		ListNode a2 = new ListNode (4);
		ListNode a3 = new ListNode (3);
		ListNode a4 = new ListNode (2);
		ListNode a5 = new ListNode (1);
		a5.next = a4; a4.next = a3; a3.next = a2; a2.next = a1; a1.next = null;
		printList(a5);
		System.out.println("");
		ListNode head = reverseBetween(a5, 2, 4);
		printList(head);
	}
}
