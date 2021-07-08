#include<iostream>
#include<vector>
using namespace std;

class Solution{
	public:
		int findLength(vector<int> &nums1, vector<int> &nums2){
			int n = nums1.size(), m = nums2.size(), res = 0;
			vector<vector<int> > dp(n+1, vector<int>(m+1, 0));
			
			for (int i = 0; i <= n; ++i){
				for(int j = 0; j <= m; ++j){
					dp[i][j] = nums1[i-1] == nums2[j-1] ? 1 + dp[i-1][j-1] : 0;
					res = max(res, dp[i][j]);
				}
			}
			
			return res;
		}
};

int main(){
	vector<int> nums1;
	nums1.push_back(1);
	nums1.push_back(2);
	nums1.push_back(3);
	nums1.push_back(2);
	nums1.push_back(1);
	
	vector<int> nums2;
	nums2.push_back(3);
	nums2.push_back(2);
	nums2.push_back(1);
	nums2.push_back(4);
	nums2.push_back(7);
	
	Solution obj;
	cout << obj.findLength(nums1, nums2);
	
	return 1;
}

//https://leetcode.com/problems/maximum-length-of-repeated-subarray/
