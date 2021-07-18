#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	
	ListNode() : val(0), next(NULL) {		
	}
	
	ListNode(int x) : val(x), next(NULL) {		
	}
	
	ListNode(int x, ListNode* next) : val(x), next(next) {
	}
};

class Solution {
	public:
		ListNode* reverseKGroup(ListNode* head, int k) {
			int count = 0;
			ListNode* cur = head;
			vector<int> nums;
			
			while(cur != NULL) {
				nums.push_back(cur->val);
				cur = cur->next;
				count ++;
			}
			
			for(int i = 0; i < count; i += k) {
				for(int j = 0; j < k/2 && i+k-1-j < count; ++j){
					int cur = nums[i+j];
					nums[i+j] = nums[i+k-1-j];
					nums[i+k-1-j] = cur;
				}
			}
			
			ListNode* newHead = new ListNode(nums[0]);
			ListNode* curNode = newHead;
			newHead->next = curNode;
			
			for(int i = 1; i < count; ++i){
				ListNode* newNode = new ListNode(nums[i]);
				curNode->next = newNode;
				curNode = curNode->next;
			}
			
			curNode->next = NULL;
			return newHead;
		}
		
		void printNode(ListNode *head){
			ListNode* cur = head;
			while(cur != NULL){
				cout << cur->val ;
				if(cur->next == NULL){
					cout << endl;
				}
				else{
					cout << " -> ";
				}
				cur = cur->next;
			}
		}
};

int main(){
	ListNode* a15 = new ListNode(15, NULL);
	ListNode* a14 = new ListNode(14, a15);
	ListNode* a13 = new ListNode(13, a14);
	ListNode* a12 = new ListNode(12, a13);
	ListNode* a11 = new ListNode(11, a12);
	ListNode* a10 = new ListNode(10, a11);
	ListNode* a9 = new ListNode(9, a10);
	ListNode* a8 = new ListNode(8, a9);
	ListNode* a7 = new ListNode(7, a8);
	ListNode* a6 = new ListNode(6, a7);
	ListNode* a5 = new ListNode(5, a6);
	ListNode* a4 = new ListNode(4, a5);
	ListNode* a3 = new ListNode(3, a4);
	ListNode* a2 = new ListNode(2, a3);
	ListNode* a1 = new ListNode(1, a2);

	
	Solution obj;
	obj.printNode(a1);
	ListNode* a16 = obj.reverseKGroup(a1, 2);
	obj.printNode(a16);
	
	return 1;
	
}

//https://leetcode.com/problems/reverse-nodes-in-k-group/
