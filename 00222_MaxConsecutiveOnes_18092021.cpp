#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        int findMaxConsecutiveOnes(vector<int>& nums) {
            int count = 0;
            int ans = 0;
            for(int num : nums) {
                if(num == 1)
                    count ++;
                else {
                    ans = max(ans, count);
                    count = 0;
                }
            }
            return max(ans, count);
        }

        void printVector(vector<int>& nums) {
            cout << "[";
            for(int num : nums) 
                cout << " " << num << " ";
            cout << "]" << endl;
        }
};

int main (){
    int arr[] = {0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));

    Solution obj;
    obj.printVector(nums);
    cout << "Max consecutive ones : " << obj.findMaxConsecutiveOnes(nums) << endl;

    return 1;
}

//https://leetcode.com/problems/max-consecutive-ones/