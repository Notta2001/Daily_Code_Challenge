#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* res=NULL; //the lca
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //for every node find the two values in the both left and right sub tree
        //if node->val is one of the p or q then find the other one
        //if two node values have been found then we dont search for the values in the further sub trees
        
        findLCAhelper(root,p->val,q->val);
        return res;
    }
    
    bool findLCAhelper(TreeNode* root,int p,int q)
    {
        //if we have got the nodes we are searching for
        if(!root)
            return false;
        bool found=false;
        if(root->val==p || root->val==q)
            found=true;
        bool left= findLCAhelper(root->left,p,q);
        bool right=findLCAhelper(root->right,p,q);
        //if currnode is either p or q and we have found other node from left or right
        if(found && (left || right))
        {
            res=root;
            return false;
        }
        // if we have found one of the node on left and other node on right subtree
        if(left && right )
        {
            res=root ;
            return false;
        }
        return (found || left || right);
    }
};

// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
