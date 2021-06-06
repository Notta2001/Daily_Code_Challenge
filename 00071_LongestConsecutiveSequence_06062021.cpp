#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int longestConsecutive(vector<int> &nums){
	if(nums.size() == 0) return 0;
	if(nums.size() == 1) return 1;
	sort(nums.begin(), nums.end());
	int ans = 1;
	int cur = 1;
	for(int i = 1; i < nums.size(); ++i){
		if(nums[i] == 1 + nums[i-1]){
			cur ++;
			if(cur > ans) ans = cur;
		}
		else if(nums[i] - nums[i-1] > 1){
			cur = 1;
		}
	}
	return ans;
}

int main(){
	int arr[10] = {0,3,7,2,5,8,4,6,0,1};
	vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));
	cout << longestConsecutive(nums);
}
