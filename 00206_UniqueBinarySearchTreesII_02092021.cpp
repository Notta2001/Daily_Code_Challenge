#include<iostream>
#include<vector>
using namespace std;

/*
IDEA:
    We will use a recursive helper function that recieves a range (within n) and returns all subtrees in that range
    We have a few cases:
        1. If start > end, which is not supposed to happen, we return a list that contains only a null
        2. If start == end it means we reached a leaf and we will return a list containing a tree that has only that node
        3. Otherwise
            for each option of root, we get all possible subtress with that root for left and right children
            Then for each possible pair of left and right we add to the result a new tree
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(NULL), right(NULL) {};
    TreeNode(int x): val(x), left(NULL), right(NULL) {};
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {} ;
};

class Solution {
    public:
        vector<TreeNode*> rec(int start, int end) {
            vector<TreeNode*> res;
            if(start > end) return {NULL};

            if(start == end) return {new TreeNode(start)};

            for(int i = start; i <= end; ++i) {
                vector<TreeNode*> left = rec(start, i-1),  right = rec(i+1, end);
                for(auto l : left) 
                    for(auto r: right)
                        res.push_back(new TreeNode(i, l, r));
            }
            return res;
        }

        vector<TreeNode*> generateTrees(int n) {
            vector<TreeNode*> res = rec(1, n);
            cout << res.size() << endl;
            return res;
        }
};

int main(){
    Solution obj;
    obj.generateTrees(3);

    return 1;
}
//https://leetcode.com/problems/unique-binary-search-trees-ii/