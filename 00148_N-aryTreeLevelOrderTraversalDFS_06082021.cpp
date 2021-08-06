#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Node {
	public: 
		int val;
		vector<Node*> children;
		
		Node(){}
		
		Node(int _val){
			val = _val;
		}
		
		Node(int _val, vector<Node*> _children) {
			val = _val;
			children = _children;
		}
};

class Solution {
	public: 
		vector<vector<int> > ans;
		vector<int> val;
		
		void dfs(Node *root, int level) {
			if(root == NULL) return;
			if(level == ans.size()) ans.push_back(val); // Need more level -> add new level
			ans[level].push_back(root->val);
			
			for(int i = 0; i < root->children.size(); ++i){
				dfs(root->children[i], level + 1);
			}
		}
		
		vector<vector<int> > levelOrder(Node* root){
			dfs(root, 0);
			return ans;	
		}
		
		void printVect(vector<vector<int> > res){
			cout << "[";
			for(int i = 0; i < res.size(); ++i){
				cout << "[";
				for(int j = 0; j < res[i].size(); ++j){
					cout << " " << res[i][j] << " ";
				}
				cout << "]";
			}
			cout << "]" << endl;
		}
		
		
};

int main (){
	Node* a1 = new Node(1);
	Node* a2 = new Node(2);
	Node* a3 = new Node(3);
	Node* a4 = new Node(4);	
	Node* a5 = new Node(5);
	Node* a6 = new Node(6);
	
	vector<Node*> nums;
	nums.push_back(a3);
	nums.push_back(a2);
	nums.push_back(a4);
	a1->children = nums;

	nums.clear();
	nums.push_back(a5);
	nums.push_back(a6);
	a3->children = nums;

	Solution obj;
	vector<vector<int> > res = obj.levelOrder(a1);
	obj.printVect(res);
	
	return 1;
}
//https://leetcode.com/problems/n-ary-tree-level-order-traversal/
