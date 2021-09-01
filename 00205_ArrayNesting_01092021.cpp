#include<iostream>
#include<vector>
using namespace std;

/*
Idea
    Elements in the same set will form a cycle 
    We just traverse elements x in nums:
        If x is not visited then we dfs(x) to find elements in the same cycle with node x
        Update the ans if the current cycle has length greater than ans
    For instance [5, 4, 0, 3, 1, 6, 2] has 3 cycles [5, 6, 2, 0], [4, 1] , [3]
*/

class Solution {
    public:
        int arrayNesting(vector<int>& nums) {
            int res = 0, curr, count, prev;
            for(int i = 0; i < nums.size(); ++i) {
                if(nums[i] == -1) continue;
                curr = nums[i], count = 1, nums[i] = -1;

                while(nums[curr] != -1) {
                    prev = curr;
                    curr = nums[curr];
                    nums[prev] = -1;
                    count ++;
                }

                res = max(res, count);
            }
            return res;
        }

        void printVect(vector<int>& nums) {
            cout << "[" ;
            for(int i = 0; i < nums.size(); ++i)
                cout << " " << nums[i] << " ";
            cout << "]" << endl;
        }
};

int main () {
    int arr[] = {5, 4, 0, 3, 1, 6, 2};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));

    Solution obj;
    obj.printVect(nums);
    cout << obj.arrayNesting(nums) << endl;

    return 1;
}

//https://leetcode.com/problems/array-nesting/