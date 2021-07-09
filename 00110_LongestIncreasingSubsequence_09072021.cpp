#include<iostream>
#include<vector>
using namespace std;

class Solution{
	public:
		int lengthOfLIS(vector<int> &a){
			int n = a.size();
			if(n == 1) return 1;
			int f = 0;
			vector<int> t(n, 0);
			t[0] = 1;
			for(int i = 1; i < n; ++i){
				t[i] = 1;
				for(int j = 0; j < i; ++j){
					if(a[j] < a[i] && t[i] < (t[j] + 1)){
						t[i] = t[j] + 1;
					}
				}
			}
			
			for(int i = 0; i < t.size(); ++i){
				if(t[i] > f){
					f = t[i];
				}
			}
			
			return f;
		}
};

int main(){
	int arr[] = {10,9,2,5,3,7,101,18};
	vector<int> nums(arr, arr + sizeof(arr)/ sizeof(int));
	Solution obj;
	cout << obj.lengthOfLIS(nums);
	return 1;
}

//https://leetcode.com/problems/maximum-length-of-repeated-subarray/
