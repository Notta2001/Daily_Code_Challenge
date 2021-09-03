#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public: 
        int minimumDifference(vector<int>& nums, int k) {
            if(k == 1)
                return 0;
            sort(nums.begin(), nums.end());
            int ans = INT_MAX;
            for(int i = 0; i <= nums.size() - k; ++i) {
                ans = min(ans, nums[i + k - 1] - nums[i]);
            }
            return ans;
        }

        void printVect(vector<int>& nums) {
            cout << "[" ;
            for(int num : nums) 
                cout << " " << num << " ";
            cout << "]" << endl; 
        }
};

int main() {
    int arr[] = {9, 4, 1, 7};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));

    Solution obj;
    obj.printVect(nums);
    cout << obj.minimumDifference(nums, 2) << endl;

    return 1;
}

//https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/