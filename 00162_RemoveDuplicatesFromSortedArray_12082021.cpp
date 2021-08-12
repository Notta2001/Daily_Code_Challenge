#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        void printVect(vector<int>& nums, int k) {
            cout << "[";
            for(int i = 0; i < k; ++i)
                cout << nums[i];
            cout << "]" << endl;
        }

        int removeDuplicates(vector<int>& nums){
            printVect(nums, nums.size());
            int i = 0;
            int j = 1;
            if(nums.size() == 0) 
                return 0;
            while(j < nums.size()) {
                if(nums[i] == nums[j])
                    j++;
                else {
                    i++;
                    nums[i] = nums[j];
                    j ++;
                }
            }
            printVect(nums, i+2);
            return i+1;
        }
};

int main() {
    int arr[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));

    Solution obj;
    cout << obj.removeDuplicates(nums) << endl;

    return 1;
}

//https://leetcode.com/problems/remove-duplicates-from-sorted-array/