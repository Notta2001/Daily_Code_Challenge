#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        int findMin(vector<int>& nums) {
            int r = nums.size() - 1, l = 0, mid;
            if(!r) return nums[0]; // only one element

            while(l < r) {
                mid = l + (r - l) / 2;

                // got a part that is not rotated
                if(nums[l] < nums[r]) return nums[l];

                // mid is larger than right - min is in right side
                else if (nums[mid] > nums[r]) l = mid + 1;

                // mid is smaller than right - min is in left side (including mid)
                else r = mid;
            }
            return nums[l];
        }

        void printVect(vector<int> &nums) {
            cout << "[" ;
            for(int i = 0; i < nums.size(); ++i) {
                cout << " " << nums[i] << " " ;
            }
            cout << "]" << endl;
        }
};

int main () {
    int arr[] = {5, 6, 7, 8, 9, 0, 1, 2, 3, 4};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));

    Solution obj;
    obj.printVect(nums);
    cout << obj.findMin(nums) << endl;

    return 1;
}

//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/