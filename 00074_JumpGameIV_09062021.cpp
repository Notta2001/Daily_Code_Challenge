#include<iostream>
#include<vector>
#include <set>
using namespace std;

int maxResult(vector<int>& nums, int k) {
    int n = nums.size();
    multiset<int, greater<int> > ms;
    multiset <int, greater <int> > :: iterator itr;
    ms.insert(nums[0]);
    for (int i = 1; i < n; i++) {
    	if(ms.size() > k){
    		ms.erase(ms.find(nums[i-k-1]));
		}
    	itr = ms.begin();
    	nums[i] += *(itr);
    	ms.insert(nums[i]);
    }
    return nums[n-1];
}

int main(){
	int arr[] = {1,-5,-20,4,-1,3,-6,-3};
	int k = 2 ;
	vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
	cout << maxResult(nums, k);
	return 0;
}
