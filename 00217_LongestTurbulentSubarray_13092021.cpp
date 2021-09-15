#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        int maxTurbulenceSize(vector<int>& arr) {
            int n = arr.size(), up = 1, down = 1, res = 1;
            for(int i = 1; i < n; ++i) {
                if(arr[i] > arr[i-1]) 
                    up = down + 1;
                else if(arr[i] < arr[i-1]) 
                    down = up + 1;
                if(arr[i-1] >= arr[i])
                    up = 1;
                if(arr[i-1] <= arr[i])
                    down = 1;
                res = max(res, max(up, down));
            }
            return res;
        }

        void printVect(vector<int>& arr) {
            cout << "[";
            for(int num : arr) 
                cout << " " << num << " ";
            cout << "]" << endl;
        }
};

int main () {
    int arr[] = {9, 4, 2, 10, 7, 8, 8, 1, 9};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));

    Solution obj;
    obj.printVect(nums);
    cout << obj.maxTurbulenceSize(nums) << endl;

    return 1;
}
//https://leetcode.com/problems/longest-turbulent-subarray/