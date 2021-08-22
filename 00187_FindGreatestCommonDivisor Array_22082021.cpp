#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        int gcd(int a, int b) {
            if (a == 0)
                return b;
            return gcd(b % a, a);
        }

        int findGCD(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            return gcd(nums[0], nums[nums.size() - 1]);
        }

        void printVect(vector<int> nums){
            for(int i = 0; i < nums.size(); ++i)
                cout << nums[i] << " ";
            cout << endl;
        }
};

int main () {
    int arr[] = {2, 5, 6, 9, 10};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));

    Solution obj;
    obj.printVect(nums);
    cout << obj.findGCD(nums) << endl;

    return 1;
}

//https://leetcode.com/problems/find-greatest-common-divisor-of-array/