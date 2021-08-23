#include<iostream>
#include<vector>
using namespace std;

/*
    Since our Binary Tree is a Binary Search Tree, when we traverse elements in-order, elements are sorted
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(NULL), right(NULL) {};
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {};
};

class Solution {
    private:
        vector<int> nums;

        void printVect(vector<int>& nums) {
            cout << "[";
            for(int i = 0; i < nums.size(); ++i)
                cout << " " << nums[i] << " ";
            cout << "]" << endl;
        }
    public:
        void inorder(TreeNode* root) {
            if(!root)
                return;
            inorder(root->left);
            nums.push_back(root->val);
            inorder(root->right);
        }

        bool findTarget(TreeNode* root, int k) {
            inorder(root);
            printVect(nums);

            int left = 0, right = nums.size() - 1;
            while(left < right) {
                if(nums[left] + nums[right] == k)
                    return true;
                else if(nums[left] + nums[right] < k)
                    left ++;
                else 
                    right --;
            }
            return false;
        }
};

int main () {
    TreeNode* a1 = new TreeNode(2);
    TreeNode* a2 = new TreeNode(4);
    TreeNode* a3 = new TreeNode(7);
    TreeNode* a4 = new TreeNode(3, a1, a2);
    TreeNode* a5 = new TreeNode(6, NULL, a3);
    TreeNode* a6 = new TreeNode(5, a4, a5);

    Solution obj;
    cout << obj.findTarget(a6, 9) << endl;

    return 1;
}

//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/