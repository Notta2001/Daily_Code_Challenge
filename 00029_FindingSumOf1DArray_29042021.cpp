#include<iostream>
#include<vector>
using namespace std;

vector<int> runningSum(vector<int> & nums){
	int curSum = 0;
	vector<int> res;
	for(int i = 0; i < nums.size(); ++i){
		curSum += nums[i];
		res.push_back(curSum);
	}
	return res;
}

void print(const vector<int> &nums){
	for(int i = 0; i < nums.size(); ++i){
		cout<< nums[i] << " " ;
	}
	cout << endl;
}

int main(){
	int arr[5] = {1, 2, 3, 4, 5};
	vector<int> init(&arr[0], &arr[0] + 5);
	vector<int> res = runningSum(init);
	print(init);
	print(res);
	return 0;
}

// https://leetcode.com/problems/running-sum-of-1d-array/