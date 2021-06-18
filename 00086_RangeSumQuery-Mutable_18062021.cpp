#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class NumArray {
public:
    NumArray(vector<int> nums) {
        n = nums.size();
        if (n==0){return;}
        this->nums = nums;
        segTree = constructSegTree(nums, 0, n-1);
        //checkSegTree(segTree);
    }
    
    void update(int i, int val) {
        //cout << "updating i=" << i << ", val = " << val << endl;
        updateSegTree(segTree, 0, n-1, i, val);
        nums[i] = val;
        //checkSegTree(segTree);
    }
    
    int sumRange(int i, int j) {
        return treeSum(segTree, 0, n-1, i, j);
    }
    
private:
    struct TreeNode
    {
        int value;
        TreeNode* left;
        TreeNode* right;
    }; 
    
    TreeNode* segTree; // segmentation tree
    vector<int> nums;  // input array
    int n;             // length of input array
    
    TreeNode* constructSegTree(const vector<int>& nums, int st, int ed){
        TreeNode *tnode = new TreeNode();
        if (st == ed){
            tnode->value = nums[st];
            //cout << "set value to node: " << nums[st] << endl;
        }else{
            int mid = st + (ed-st)/2;
            //cout << "mid = " << mid << endl;
       
            tnode->left = constructSegTree(nums, st, mid);
            //cout << "left val:" << tnode->left->value << endl;
            
            tnode->right = constructSegTree(nums, mid+1, ed);
            //cout << "right val:" << tnode->right->value << endl;
            
            tnode->value = tnode->left->value + tnode->right->value;
            //cout << "value= " << tnode->value << endl;
        }
        
        return tnode;
    }
    
    int treeSum(TreeNode* segTree, int st, int ed, int l, int r){
        if (st >= l && ed <= r){
            return segTree->value;
        }else if (ed < l || st > r){
            return 0;
        }else{
            int mid = st + (ed-st)/2;
            return treeSum(segTree->left, st, mid, l, r) + treeSum(segTree->right, mid+1, ed, l, r);
        }
    }
    
    void updateSegTree(TreeNode* segTree, int st, int ed, int i, int val){
        int mid = st + (ed-st)/2;
        int diff = val - nums[i];
        //cout << "diff=" << diff << endl;
        //cout << "st, ed = " << st << ",  " << ed << endl;
        if (st == ed){
            segTree->value += diff;
        }else if (i <= mid){
            segTree->value += diff;
            updateSegTree(segTree->left, st, mid, i, val);
        }else{
            segTree->value += diff;
            updateSegTree(segTree->right, mid+1, ed, i, val);
        }
    }
    
    // print segTree level by level (debug only)
    void checkSegTree(TreeNode* segTree){
        //cout << "Printing segTree structure" << endl;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(segTree);
        while (!q1.empty()){
            while (!q1.empty()){
                TreeNode* tmp = q1.front();
                q1.pop();
                if (tmp->left){ q2.push(tmp->left);}
                if (tmp->right){ q2.push(tmp->right);}
            }
            q1 = q2;
            q2 = queue<TreeNode*>();
        }
    }
};

//http://yucoding.blogspot.com/2017/03/leetcode-question-range-sum-query.html (read code in the future);

int main(){
	int arr[] = {1, 3, 5, 7, 9, 11};
	vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));
	NumArray* obj = new NumArray(nums);
 	obj->update(2,3);
 	int param_2 = obj->sumRange(1,4);
 	cout << param_2 << endl;
}
