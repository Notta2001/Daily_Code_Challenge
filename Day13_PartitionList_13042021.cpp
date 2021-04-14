//head = [1,4,3,2,5,2], x = 3 => [1,2,2,4,3,5]
//Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
//You should preserve the original relative order of the nodes in each of the two partitions.

#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode*partition(ListNode* head, int x){
	if(head == NULL){
		return NULL;
	}
	ListNode* lessDummy = new ListNode(-1);
	ListNode* greaterOrEqualDummy = new ListNode(-1);
	ListNode* lessIter = lessDummy;
	ListNode* greaterOrEqualIter = greaterOrEqualDummy;
	ListNode* iter = head;
	while(iter != NULL){
		if(iter->val < x){
			lessIter->next = iter;
			lessIter = iter;
		}
		else{
			greaterOrEqualIter->next = iter;
			greaterOrEqualIter = iter;
		}
		iter = iter->next; 
	}
	greaterOrEqualIter->next = NULL;
	lessIter->next = greaterOrEqualDummy->next;
	return lessDummy->next;
}

void printList(ListNode*head){
	ListNode* cur = head;
	while(cur != NULL){
		cout << cur->val << " " ; 
		cur = cur->next;
	}
	cout<<endl;
}

int main(){
	ListNode* a = new ListNode(1);
	ListNode* b = new ListNode(4);
	ListNode* c = new ListNode(3);
	ListNode* d = new ListNode(2);
	ListNode* e = new ListNode(5);
	ListNode* f = new ListNode(2);
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;
	e->next = f;
	f->next = NULL;
	int x = 3;
	printList(a);
	a = partition (a , 3);
	printList(a);
	return 0; 
}
