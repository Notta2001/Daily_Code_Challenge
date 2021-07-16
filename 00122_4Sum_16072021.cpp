#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// remember the combination of 4 elements need to be unique

class Solution{
	public:
		vector<vector<int> > fourSum(vector<int>& nums, int target){
			if(nums.empty() || nums.size() < 4) return {};
			vector<vector<int> > res;
			sort(nums.begin(), nums.end());
			int n = nums.size(), a, b, c, d;
			
			for(a = 0; a < n-3; ++a){
				if(a > 0 && nums[a] == nums[a-1]) continue; // get rid of make a duplicate combination
				for(b = a + 1; b < n -2; ++b){
					if(b > a+1 && nums[b] == nums[b-1]) continue; // get rid of make a duplicate combination
					c = b+1, d = n-1; // we just need c = b +1 because another case already occur
					while(c < d){
						int sum = nums[a] + nums[b] + nums[c] + nums[d];
						if(sum < target) c++;
						else if (sum > target) d--;
						else{
							vector<int> ans;
							ans.push_back(nums[a]);
							ans.push_back(nums[b]);
							ans.push_back(nums[c]);
							ans.push_back(nums[d]);
							res.push_back(ans);
							while(c < d && nums[c] == nums[c+1]) c++; // one more time here we set a while loop bcs we don't wanna make a duplicate combination
							while(c < d && nums[d] == nums[d-1]) d--;
							c++;
							d--;
						}
					}
				}
			}
			return res;
		}
		
		void printVect(vector<vector<int> > res){
			for(int i = 0; i < res.size(); ++i){
				cout << "[";
				for(int j = 0; j < 4; ++j){
					cout << " " << res[i][j] << " ";
				}
				cout << "]" << endl;
			}
		}
};

int main(){
	int arr[] = {1, 0, -1, 0, -2, 2};
	vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
	Solution obj;
	vector<vector<int> > res = obj.fourSum(nums, 0);
	obj.printVect(res);
	return 1;
}

//https://leetcode.com/problems/4sum/
