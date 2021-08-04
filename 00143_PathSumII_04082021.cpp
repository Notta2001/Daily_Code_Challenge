#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(NULL), right(NULL) {}
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
	public:
		void pathStore(TreeNode* root, vector<int>& path, int targetSum, vector<vector<int> >& res) {
			if(root == NULL)
				return;
			path.push_back(root->val);
			
			if(root->right == NULL and root->left == NULL and targetSum == root->val) {
				res.push_back(path);
				path.pop_back();
				return;
			}
			
			pathStore(root->left, path, targetSum - root->val, res);
			pathStore(root->right, path, targetSum - root->val, res);
			path.pop_back();
		}
		
		vector<vector<int> > pathSum(TreeNode* root, int targetSum) {
			vector<int> path;
			vector<vector<int> > res;
			pathStore(root, path, targetSum, res);
			
			return res;
		}
		
		void printVect(vector<vector<int> > res) {
			cout << "[";
			for(int i = 0; i < res.size(); ++i){
				cout << "[";
				for(int j = 0; j < res[i].size(); ++j) {
					cout << " " << res[i][j] << " ";
				}
				cout << "]";
			}
			cout << "]";
		}
};

int main() {
	TreeNode* a1 = new TreeNode(7);
	TreeNode* a2 = new TreeNode(2);
	TreeNode* a3 = new TreeNode(5);
	TreeNode* a4 = new TreeNode(1);
	TreeNode* a5 = new TreeNode(11, a1, a2);
	TreeNode* a6 = new TreeNode(4, a3, a4);
	TreeNode* a7 = new TreeNode(13);
	TreeNode* a8 = new TreeNode(8, a7, a6);
	TreeNode* a9 = new TreeNode(4, a5, NULL);
	TreeNode* a10 = new TreeNode(5, a9, a8);
	
	Solution obj;
	vector<vector<int> > res = obj.pathSum(a10, 22);
	obj.printVect(res);
	
	return 1;
}

//https://leetcode.com/problems/path-sum-ii/
