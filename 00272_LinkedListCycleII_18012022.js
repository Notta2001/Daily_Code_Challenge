var detectCycle = function(head) {
    let fast = head;
    let slow = head;
    let isCycle = false;
    
    if(!fast || !fast.next || !fast.next.next) return null;
    
    do{
        fast = fast.next.next;
        slow = slow.next;
        if(fast === slow){
            isCycle = true;
            break;
        }
    }while(fast && fast.next !== null && fast.next.next !== null );
    
    if(!isCycle) return null;
    
    fast = head;
    while(fast !== slow){
        fast = fast.next;
        slow = slow.next;
    }
    
    return slow;
};

// https://leetcode.com/problems/linked-list-cycle-ii/