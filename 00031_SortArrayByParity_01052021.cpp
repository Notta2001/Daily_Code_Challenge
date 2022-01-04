#include<iostream>
#include<vector>
using namespace std;

void swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

void sortArrayByParity(vector<int> &nums){
	int n = nums.size();
	int i = 0;
	int j = n-1;
	while(i < j){
		if(nums[i] % 2 == 1){
			if(nums[j] % 2 == 0 && i < j){
				swap(nums[i], nums[j]);
			}
			else{
				j--;
			}
		}
		else{
			++i;
		}
	}	
}

void print(const vector<int> &nums){
	for(int i = 0; i < nums.size(); ++i){
		cout << nums[i] << " ";
	}
	cout << endl;
}

int main(){
	int arr[15] = {2, 1, 2, 1, 1, 2, 1, 2, 1, 1, 2, 1, 1, 2, 1};
	vector<int> init(arr, arr+sizeof(arr)/sizeof(int));
	print(init);
	sortArrayByParity(init);
	print(init);
	return 0;
}

// https://leetcode.com/problems/sort-array-by-parity/