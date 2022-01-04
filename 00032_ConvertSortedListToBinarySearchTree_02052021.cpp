#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(NULL){}
	ListNode(int x) : val(x), next(NULL){}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(NULL), right(NULL){}
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right){}
};

TreeNode* sortedListToBSTHelper(vector<int> nums, int start, int end){
	if (start <= end) {
		cout << nums[start + (end - start) / 2] << " " << start << " " << end << endl ;
        TreeNode *node = new TreeNode(nums[start + (end - start) / 2]);
        node->left = sortedListToBSTHelper(nums, start, start + (end - start) / 2 - 1);
        node->right = sortedListToBSTHelper(nums, start + (end - start) / 2 + 1, end);
        return node;
    }
	return NULL;
}

TreeNode* sortedListToBST(ListNode* head){
	vector<int> nums;
	ListNode* curNode = head;
	while(curNode != NULL){
		nums.push_back(curNode->val);
		curNode = curNode->next;
	}
	return sortedListToBSTHelper(nums, 0, nums.size() - 1);
}

void printTree(TreeNode* head){
	queue<TreeNode*> q;
	TreeNode* curNode = head;
	q.push(curNode);
	while(!q.empty()){
		TreeNode* cur = q.front();
		cout << cur->val << " ";
		if(cur->left == NULL && cur->right == NULL){
			q.push(cur->left);
			q.push(cur->right);
		}
		q.pop();
	}
}

int main(){
	ListNode* n1 = new ListNode(-10);
	ListNode* n2 = new ListNode(-3);
	ListNode* n3 = new ListNode(0);
	ListNode* n4 = new ListNode(5);
	ListNode* n5 = new ListNode(9);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = NULL;
	TreeNode* head = sortedListToBST(n1);
	printTree(head);
	return 0;
}

// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/