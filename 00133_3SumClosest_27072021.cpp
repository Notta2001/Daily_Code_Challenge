#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
	public:
		int threeSumClosest(vector<int>& nums, int target){
			sort(nums.begin(), nums.end());
			int minDis = INT_MAX;
			int minRes = INT_MAX;
			for(int i = nums.size()-1; i >= 2; --i){
				int left = 0;
				int right = i-1;
				while(left < right){
					int total = nums[left] + nums[right] + nums[i];
					if(total == target) 
						return target;
					else if(total < target)
						left ++;
					else
						right--;
						
					if(abs(target-total) < minDis) 
						minRes = total;
				}
			}
			return minRes;
		}
};

int main(){
	int arr[] = {-1, 2, 1, -4};
	vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
	Solution obj;
	cout << obj.threeSumClosest(nums, 2);
	return 1; 
}

//https://leetcode.com/problems/3sum-closest/
