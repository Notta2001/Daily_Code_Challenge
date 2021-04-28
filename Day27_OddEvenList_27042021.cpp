#include<iostream>
using namespace std;

struct ListNode {
	int val;
   	ListNode *next;
	ListNode() : val(0), next(NULL) {}
	ListNode(int x) : val(x), next(NULL) {}
   	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* oddEvenList(ListNode* head){
	ListNode* curNode = head;
	int index = 1;
	ListNode* theLastOddNode = NULL;
	ListNode* theLastEvenNode = NULL;
	while(curNode != NULL){
		ListNode* nextNode = curNode->next;
		if(index == 1){
			theLastOddNode = curNode;
		}
		else if(index == 2){
			theLastEvenNode = curNode;
		}
		else{
			if(index % 2 != 0){
				curNode->next = theLastOddNode->next;
				theLastOddNode->next = curNode;
				theLastEvenNode->next = nextNode;
			}
			else{
				theLastEvenNode = theLastEvenNode->next;
				theLastOddNode = theLastOddNode->next;
			}
		}
		index ++;
		curNode = nextNode;
	}
	return head;
}

void print(ListNode* head){
	ListNode* curNode = head;
	while(curNode != NULL){
		cout << curNode->val << " " ;
		curNode = curNode->next;
	}
	cout << endl;
}

int main(){
	ListNode* a1 = new ListNode(1);
	ListNode* a2 = new ListNode(2);
	ListNode* a3 = new ListNode(3);
	ListNode* a4 = new ListNode(4);
	ListNode* a5 = new ListNode(5);
	ListNode* a6 = new ListNode(6);
	ListNode* a7 = new ListNode(7);
	ListNode* a8 = new ListNode(8);
	ListNode* a9 = new ListNode(9);
	ListNode* a10 = new ListNode(10);
	a1->next = a2;
	a2->next = a3;
	a3->next = a4;
	a4->next = a5;
	a5->next = a6;
	a6->next = a7;
	a7->next = a8;
	a8->next = a9;
	a9->next = a10;
	a10->next = NULL;
	print(a1);
	a1 = oddEvenList(a1);
	print(a1);
	return 0;
}
