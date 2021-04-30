#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode() : val(0), next(NULL) {}
	ListNode(int x) : val(x), next(NULL) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* swapNodes(ListNode* head, int k){
	vector<int> represent;
	ListNode* cur = head;
	while(cur != NULL){
		represent.push_back(cur->val);
		cur = cur->next;
	}
	int temp = represent[k-1];
	represent[k-1] = represent[represent.size() - k];
	represent[represent.size()-k] = temp;
	ListNode* newHead = new ListNode(represent[0]);
	ListNode* moveNode = newHead;
	for(int i = 1; i < represent.size(); ++i){
		ListNode* nextNode = new ListNode(represent[i]);
		moveNode->next = nextNode;
		moveNode = nextNode;
	}
	return newHead;
}

void printListNode(ListNode* head){
	ListNode* cur = head;
	while(cur != NULL){
		cout << cur->val <<  " ";
		cur = cur->next;
	}
	cout << endl;
}

int main(){
	ListNode* a = new ListNode(1);
	ListNode* b = new ListNode(2);
	ListNode* c = new ListNode(3);
	ListNode* d = new ListNode(4);
	ListNode* e = new ListNode(5);
	a->next = d;
	d->next = c;
	c->next = b;
	b->next = e;
	e->next = NULL;
	cout << "Initial List Node : " <<endl;
	printListNode(a);
	cout << "List Node After Swap : " << endl;
	ListNode* head = swapNodes(a,2);
	printListNode(head);
	return 0;
}
