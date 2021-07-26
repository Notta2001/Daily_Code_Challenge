#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(NULL), right(NULL) {}
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
	public: 
		TreeNode* rec(vector<int>& nums, int start, int end){
			if(start >= end) return NULL;
			int mid = (start + end) / 2;
			TreeNode* node = new TreeNode(nums[mid]);
			node->left = rec(nums, start, mid);
			node->right = rec(nums, mid+1, end);
			return node;	
		}
		
		TreeNode* sortedArrayToBST(vector<int>& nums) {
			return rec(nums, 0, nums.size());
		}
		
		void printTree(TreeNode* head){
			TreeNode *cur = head;
			queue<TreeNode *> q;
			q.push(cur);
			while(!q.empty()){
				int n = q.size();
				for(int i = 0; i < n; ++i){
					TreeNode *node = q.front();
					if(node->left != NULL)
						q.push(node->left);
					if(node->right != NULL)
						q.push(node->right);
					cout <<" " << node->val << " ";
					q.pop(); 
				}
				cout << endl;
			}
		}
};

int main(){
	int arr[] = {-10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
	Solution obj;
	TreeNode *head = obj.sortedArrayToBST(nums);
	obj.printTree(head);
	
	return 1;
}
