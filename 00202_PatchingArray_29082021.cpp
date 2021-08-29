#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        int minPatches(vector<int>& a, int n) {
            long long int sum = 0;
            int ans = 0;
            for(int i = 0; i < a.size(); ++i) {
                while(sum + 1 < a[i] && sum < n) {
                    sum += (sum + 1);
                    ans ++;
                }
                sum += a[i];
            }
            while(sum < n) {
                sum += (sum+1);
                ans ++;
            }
            return ans;
        }
};

int main () {
    int arr[] = {1, 3, 10};
    vector<int> a(arr, arr + sizeof(arr)/sizeof(int));

    Solution obj;
    cout << obj.minPatches(a, 20);

    return 1;
}
//https://leetcode.com/problems/patching-array/