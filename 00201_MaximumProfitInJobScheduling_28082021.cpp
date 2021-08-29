#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
            int dp[50002];
            int n = startTime.size();
            vector<vector<int>> arr;
            for(int i = 0; i < startTime.size(); ++i) 
                arr.push_back({startTime[i], endTime[i], profit[i]});
            sort(arr.begin(), arr.end());
            for(int i = 0; i < arr.size(); ++i) 
                cout << arr[i][0] << " " << arr[i][1] << " " << arr[i][2] << endl;
            dp[n] = 0;
            for(int i = n-1 ; i >= 0 ; i--){
                int key = arr[i][1];
                int lo = i+1 , hi = n-1 , mid;
                while(lo < hi){
                    // mid
                    mid = lo + (hi-lo)/2;
                    // decision
                    if(arr[mid][0] >= key){
                        hi = mid;
                    }
                    else{
                        lo = mid+1;
                    }
                }
                // sanity check
                int idx = lo;
                if(lo == n || arr[lo][0] < arr[i][1]){
                    idx = n;
                }
                dp[i] = max(arr[i][2] + dp[idx] , dp[i+1]);
            }
            return dp[0];
        }
};

int main() {
    int arr1[] = {1, 2, 3, 3};
    int arr2[] = {3, 4, 5, 6};
    int arr3[] = {50, 10, 40, 70};
    vector<int> startTime(arr1, arr1 + sizeof(arr1) / sizeof(int));
    vector<int> endTime(arr2, arr2 + sizeof(arr2) / sizeof(int));
    vector<int> profit(arr3, arr3 + sizeof(arr3) / sizeof(int));

    Solution obj;
    cout << obj.jobScheduling(startTime, endTime, profit) << endl;

    return 1;
}

// https://leetcode.com/problems/maximum-profit-in-job-scheduling/