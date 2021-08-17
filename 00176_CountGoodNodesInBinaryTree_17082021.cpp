#include<iostream>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(NULL), right(NULL) {}
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution {
    public: 
        int goodNodes(TreeNode* root) {
            queue<TreeNode*> q;
            int ans = 1;
            q.push(root);
            while(!q.empty()) {
                TreeNode* cur = q.front();

                if(cur->left != NULL) {
                    if(cur->left->val >= cur->val)
                        ans += 1;
                    else
                        cur->left->val = cur->val;
                    q.push(cur->left);
                }

                if(cur->right != NULL) {
                    if(cur->right->val >= cur->val)
                        ans += 1;
                    else    
                        cur->right->val = cur->val;
                    q.push(cur->right);
                }
                q.pop();
            }
            return ans;
        }
};

int main () {
    TreeNode* a1 = new TreeNode(5);
    TreeNode* a2 = new TreeNode(1);
    TreeNode* a3 = new TreeNode(4, a2, a1);
    TreeNode* a4 = new TreeNode(3);
    TreeNode* a5 = new TreeNode(1, a4, NULL);
    TreeNode* a6 = new TreeNode(3, a5, a3);

    Solution obj;
    cout << obj.goodNodes(a6) << endl;

    return 1;
}

//https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/615/week-3-august-15th-august-21st/3899/
