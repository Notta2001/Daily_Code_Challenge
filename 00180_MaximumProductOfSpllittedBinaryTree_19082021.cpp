#include<iostream>
#include<algorithm>
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
        long long ans = 0, totalSum = 0;

        int dfs(TreeNode* root){
            if(root == NULL)
                return 0;
            int currSum = dfs(root->left) + dfs(root->right) + root->val;
            if(totalSum != 0 && currSum != totalSum) 
                ans = max(ans, (totalSum - currSum) * currSum);
            return currSum;

        }

        int maxProduct(TreeNode* root) {
            totalSum = dfs(root);
            dfs(root);
            return ans % int(1e9 + 7);
        }
};

int main(){
    TreeNode* a1 = new TreeNode(4);
    TreeNode* a2 = new TreeNode(5);
    TreeNode* a3 = new TreeNode(6);
    TreeNode* a4 = new TreeNode(2, a1, a2);
    TreeNode* a5 = new TreeNode(3, a3, NULL);
    TreeNode* a6 = new TreeNode(1, a4, a5);

    Solution obj;
    cout << obj.maxProduct(a6) << endl;

    return 1;
}
//https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/