#include<iostream>
#include<queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {
	}
};

class Solution {
	public: 
		TreeNode* lowestCommonAncestor(TreeNode* root,	TreeNode* p, TreeNode* q) {
			int a, b;
			if(p->val < q->val){
				a = p->val;
				b = q->val;
			}
			else{
				b = p->val;
				a = q->val;
			}
			TreeNode* cur = root;
			while(1){
				int c = cur->val;
				if(c >= a && c <= b)
					return cur;
				else if(c > a && c > b)
					cur = cur->left;
				else
					cur = cur->right;
            }
			return cur;
		}
		
		void printTree(TreeNode * root){
			queue<TreeNode*> q;
			TreeNode* cur = root;
			q.push(cur);
			while(!q.empty()){
				int n = q.size();
				for(int i = 0; i < n; ++i){
					TreeNode* curNode = q.front();
					cout << curNode->val << " ";
					if(curNode->left != NULL)
						q.push(curNode->left);
					if(curNode->right != NULL)
						q.push(curNode->right);
					q.pop();
				}
				cout << endl;
			}
		}
};

int main(){
	TreeNode* a1 = new TreeNode(6);
	TreeNode* a2 = new TreeNode(2);
	TreeNode* a3 = new TreeNode(8);
	TreeNode* a4 = new TreeNode(0);
	TreeNode* a5 = new TreeNode(4);
	TreeNode* a6 = new TreeNode(7);
	TreeNode* a7 = new TreeNode(9);
	TreeNode* a8 = new TreeNode(3);
	TreeNode* a9 = new TreeNode(5);
	a1->left = a2;
	a1->right = a3;
	a2->left = a4;
	a2->right = a5;
	a4->left = NULL;
	a5->left = a8;
	a5->right = a9;
	a8->left = NULL;
	a8->right = NULL;
	a9->left = NULL;
	a9->right = NULL;
	a3->left = a6;
	a3->right = a7;
	a6->left = NULL;
	a6->right = NULL;
	a7->left = NULL;
	a7->right = NULL;
	
	Solution obj;
	obj.printTree(a1);
	TreeNode* res = obj.lowestCommonAncestor(a1, a4, a6);
	cout << res->val;
	
	return 1;
}


// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
