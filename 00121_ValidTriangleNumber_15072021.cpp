#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
	public:
		int triangleNumber(vector<int>& nums) {
			int res = 0, n = nums.size();
			sort(nums.begin(), nums.end());
			
			for(int i = n-1; i > 0; --i){
				int lo = 0, hi = i-1;
				while(lo < hi){
					if(nums[lo] + nums[hi] > nums[i]) {
						res += hi - lo;
						hi --;
					}
					else lo ++;
				}
			}
			return res;
		}
};

int main () {
	int arr[] = {2, 2, 3, 4};
	vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
	Solution obj;
	cout << obj.triangleNumber(nums);
	return 1;
}


//https://leetcode.com/problems/valid-triangle-number/
