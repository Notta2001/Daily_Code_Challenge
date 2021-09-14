#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
Let dp[i][d] denotes the number of subsequences (have at least 2 numbers) that ends with nums[i] and its common difference is d
For i in [1..n-1]
    For j in [0...i-1]
        diff = nums[i] - nums[j]
        dp[i][diff] += dp[j][diff] + 1;
        ans += dp[j][diff]
    We += dp[j][diff] because it's the number of valid subsequences (have >= 3 elements). But dp[i][diff] is the number of valid subsequences 
    (have >= 2 elements)
*/

class Solution {
    public:
        int numberOfArithmeticSlices(vector<int> &nums) {
            int n = nums.size();
            int ans = 0;
            vector<unordered_map<long long, int>> dp(n);        
            for(int i = 1; i < n; ++i) {
                for(int j = 0; j < i; ++ j) {
                    long long diff = (long long) nums[i] - nums[j];
                    int cnt = dp[j].count(diff) ? dp[j][diff] : 0;
                    dp[i][diff] += cnt + 1;
                    ans += cnt;
                }
            }    
            return ans;
        }

        void printVect(vector<int>& nums) {
            cout << "[";
            for(int num : nums) 
                cout << " " << num << " ";
            cout << "]" << endl;
        }
};

int main () {
    int arr[] = {2, 4, 6, 7, 8, 10};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));

    Solution obj;
    obj.printVect(nums);
    cout << obj.numberOfArithmeticSlices(nums);

    return 1;
}

//https://leetcode.com/problems/arithmetic-slices-ii-subsequence/