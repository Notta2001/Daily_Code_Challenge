#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(NULL) {}
      ListNode(int x) : val(x), next(NULL) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr=head;
    while(curr) {
        ListNode* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
bool isPalindrome(ListNode* head) {
    int n=0;
    ListNode* iter=head;
    while(iter) iter=iter->next, n++;
    if(n<2) return true;
    // printf("-->%d\n", n);
    iter=head;
    for(int i=1;i<n/2;++i) iter=iter->next;  // 1 2 3 4 5 6 if n is even, reverse from 4 = iter->next->next; else reverse from 3 = iter -> next;
    ListNode* iter2 = (n%2) ? iter->next->next : iter->next;
    iter->next= NULL;
    // printf("iter2->val=%d\n",xiter2->val);
    iter=reverseList(head);
    while(iter) {
        if(iter->val!=iter2->val) return false;
        	iter=iter->next;
            iter2=iter2->next;
    }
    return true;
}

int main(){
	ListNode* a = new ListNode(1);
	ListNode* b = new ListNode(2);
	ListNode* c = new ListNode(2);
	ListNode* d = new ListNode(1);
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = NULL;
	cout << isPalindrome(a);
	return 0;
}


