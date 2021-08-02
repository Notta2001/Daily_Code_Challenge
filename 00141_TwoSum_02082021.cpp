#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Solution {
	public:
		vector<int> twoSum(vector<int> & nums, int target) {
			map<int, int> mp;
			vector<int> res;
			int n = nums.size();
			
			for(int i = 0; i < n; ++i){
				if(mp.count(nums[i]) > 0){
					res.push_back(mp[nums[i]]);
					res.push_back(i);
					return res;
				}
				else
					mp[target- nums[i]] = i;
			}
			
			return res;
		}
};

int main(){
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 ,20};
	vector<int> nums (arr, arr + sizeof(arr)/sizeof(int));
	
	Solution obj;
	vector<int> res = obj.twoSum(nums, 17);
	cout << nums[res[0]] << " + " << nums[res[1]] << " = " << 17 ;
	
	return 1;
}

//https://leetcode.com/problems/two-sum/
