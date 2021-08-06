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
		vector<vector<int> > levelOrder(Node* root){
			vector<vector<int> > res;
			vector<int> val;
			if(root == NULL) return res;
			queue<Node*> q;
			q.push(root);
			
			while(!q.empty()){
				res.push_back(val);
				for(int i = q.size(); i >= 1; --i){
					Node* curr = q.front(); 
					q.pop();
					res.back().push_back(curr->val);
					
					for(int j = 0; j < curr->children.size(); ++j)
						q.push(curr->children[j]);
				}
			}
			
			return res;
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
