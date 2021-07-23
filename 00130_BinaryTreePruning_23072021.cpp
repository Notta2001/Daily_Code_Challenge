#include<iostream>
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
        TreeNode* pruneTree(TreeNode* root) {
            if(!root) return NULL;

            if(root->left) 
               root->left=pruneTree(root->left);
            if(root->right) 
               root->right=pruneTree(root->right);

            if(root->val==0 && !root->left && !root->right) // remember that value 1 indicates that this is a true statement 
                return NULL;

            return root;  
        }

		void printTree(TreeNode *root){
			cout << "[";
			queue<TreeNode*> q;
			q.push(root);
			while(!q.empty()){
				TreeNode* cur = q.front();
				if(cur == NULL){
                    cout << " " << "null" << " ";
                    q.pop();
                    continue;
                }
				else
					cout << " " << cur->val << " ";
				
				if(cur->left != NULL || cur->right != NULL){
					q.push(cur->left);
					q.push(cur->right);
				}
				q.pop();
			}
			cout << "]" << endl;
		}
};

int main() {
	TreeNode* a1 = new TreeNode(0);
	TreeNode* a2 = new TreeNode(1);
	TreeNode* a3 = new TreeNode(0, a1, a2);
	TreeNode* a4 = new TreeNode(1, NULL, a3);
	
	Solution obj;
	obj.printTree(a4);
	a4 = obj.pruneTree(a4);
	obj.printTree(a4);
	
	return 1;
}


//https://leetcode.com/problems/binary-tree-pruning/
