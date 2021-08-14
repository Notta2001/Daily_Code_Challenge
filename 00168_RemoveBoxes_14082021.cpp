#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

class Solution {
    public:
        int dp[100][100][100];

        int removeBoxes(vector<int> &boxes) {
            memset(dp, 0, sizeof(dp));
            int n = boxes.size();
            return helper(boxes, 0, n-1, 0);
        }

        int helper(vector<int>& boxes, int i, int j, int k) {
            if(i > j)
                return 0;
            if(dp[i][j][k] != 0)
                return dp[i][j][k];
            int res = (k+1)*(k+1) + helper(boxes, i+1, j, 0);

            for(int range = i + 1; range <= j; range++) {
                if(boxes[i] == boxes[range])
                    res = max(res, helper(boxes, i+1, range-1, 0) + helper(boxes, range, j, k + 1));
            }

            return dp[i][j][k] = res;
        }

        void printVector(vector<int>& boxes) {
            cout << "[";
            for(int i = 0; i < boxes.size(); ++i) 
                cout << " " << boxes[i] << " ";
            cout << "]" << endl;
        }
};

int main() {
    int arr[] = {1, 3, 2, 2, 2, 3, 4, 3, 1};
    vector<int> boxes (arr, arr + sizeof(arr) / sizeof(int));

    Solution obj;
    obj.printVector(boxes);
    cout << obj.removeBoxes(boxes) << endl;

    return 1;
}

//https://leetcode.com/problems/remove-boxes/