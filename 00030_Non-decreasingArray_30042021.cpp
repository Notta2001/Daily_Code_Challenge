#include<iostream>
#include<vector>
using namespace std;

bool checkPossibility(vector<int> &nums){
	int n = nums.size();
	if(n == 1) return true;
	int count = 0;
	int first = 0;
	for(int i = 0; i < n; ++i){
		if(nums[i+1] < nums[i]){
			count ++;
			if(count == 1) first = i;
		}
	}
	if(count > 1) return false;
	else{
		if(first > 0 && nums[first-1] > nums[first+1]) return false;
		if(first < n-2 && nums[first] > nums[first+2]) return false;
	}
	return true;
}

int main(){
	int arr1[6] = {1, 3, 2, 3, 4, 5};
	int arr2[6] = {3, 3, 2, 3, 4, 5};
	vector<int> init1(&arr1[0], &arr1[0] + 6);
	vector<int> init2(&arr2[0], &arr2[0] + 6);
	cout << checkPossibility(init1) << endl;
	cout << checkPossibility(init2) << endl;
	return 0;
}

// https://leetcode.com/problems/non-decreasing-array/

