#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            int left = 0;
            int right = nums.size() - 1;
            int mid = 0;
            while(left <= right){
                mid = (left + right) / 2;
                if(nums[mid] == target)
                    return mid;
                else if(nums[mid] > target)
                    right = mid - 1;
                else    
                    left = mid + 1;
            }
            return left;
        }

        void printVector(vector<int>& nums) {
            cout << "[";
            for(int i = 0; i < nums.size(); ++i)
                cout << " " << nums[i] << " ";
            cout << "]" << endl;
        }
};

int main() {
    int arr[] = {1, 3, 5, 6};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));

    Solution obj;
    obj.printVector(nums);
    cout << obj.searchInsert(nums, 2) << endl;

    return 1;
} 

//https://leetcode.com/problems/search-insert-position/