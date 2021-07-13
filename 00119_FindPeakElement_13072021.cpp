#include<iostream>
#include<vector>
using namespace std;

class Solution {
	public :
		int findPeakElement (vector<int> & nums) {
			int n = nums.size(); 
			if (n == 1) return 0;
			if (nums[0] > nums[1]) return 0;
			if (nums[n-1] > nums[n-2]) return n-1;
			
			for (int i = 1; i < n - 1; ++i)
				if (nums[i] > nums[i-1] && nums[i] > nums[i+1])
					return i;
					
			return 0;
		}
};

int main () {
	int arr[] = {1, 2, 1, 3, 5, 6, 4};
	vector<int> nums (arr, arr + sizeof(arr) / sizeof(int));
	Solution obj;
	cout << obj.findPeakElement(nums);
	
	return 0;
}

//https://leetcode.com/problems/find-peak-element/
