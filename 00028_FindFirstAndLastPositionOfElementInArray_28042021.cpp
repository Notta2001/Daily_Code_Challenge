#include<iostream>
#include<vector>
using namespace std;

vector<int> searchRange(vector<int> &nums, int target){
	int n = nums.size();
	int high = n - 1;
	int low = 0;
	vector<int> v(2, -1);
	while(low <= high){
		int mid = (high+low)/2;
		if(nums[mid] == target){
			v[0] = mid;
			high = mid-1;
		}
		else if(target > nums[mid]){
			low =  mid + 1;
		}
		else high = mid-1;
	}
	low = 0, high = n - 1;
	while(low <= high){
		int mid = (low+high)/2;
		if(nums[mid] == target){
			v[1] = mid;
			low = mid+1;
		}
		else if(target > nums[mid]){
			low = mid+1;
		}
		else high = mid - 1;
	}
	return v;
}

void print(vector<int> &nums){
	for(int i = 0; i < nums.size(); ++i){
		cout << nums[i] << " ";
	}
	cout << endl;
}

int main(){
	int arr[6] = {5, 7, 7, 8, 8, 10};
	vector<int> nums (&arr[0], &arr[0] + 6);
	vector<int> ans = searchRange(nums, 8);
	print(ans);
	ans = searchRange(nums, 6);
	print(ans);
	return 0;
}
