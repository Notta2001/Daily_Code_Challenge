#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            int end = nums.size() - 1;
            for(int i = 0; i <= end; ++i) {
                if (nums[i] == val){
                    while (end > i && nums[end] == val)
                        end--;
                    //swap(nums[i], nums[end]);
                    int cur = nums[i];
                    nums[i] = nums[end];
                    nums[end] = cur;
                    end--;
                }
            }
            
            return end + 1;
        }

        void printVector(vector<int>& nums, int size) {
            cout << "[";
            for(int i = 0; i < size; ++i) {
                cout << " " << nums[i] << " ";
            }
            cout << "]" << endl;
        }
};

int main() {
    int arr[] = {0, 1, 2, 2, 3, 0, 4, 2};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));

    Solution obj;
    obj.printVector(nums, nums.size());
    int size = obj.removeElement(nums, 2);  
    cout << size << endl;
    obj.printVector(nums, size);

    return 1;
}

// https://leetcode.com/problems/remove-element/