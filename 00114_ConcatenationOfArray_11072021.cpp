#include<iostream>
#include<vector>
using namespace std;

class Solution {
	public : 
		vector<int> getConcatenation (vector<int> &nums) {
			int n = nums.size();
			vector<int> ans (2*n, 0);
			
			for (int i = 0; i < n; ++i){
				ans[i] = ans[i + n] = nums[i];
			}
			
			return ans;
		}
		
		void printVec (vector<int> &nums){
			cout << "[" ;
			for(int i = 0; i < nums.size(); ++i){
				cout << " " << nums[i] << " ";
			}
			cout << "]" << endl;
		}
};

int main () {
	int arr[] = {1, 3, 2, 1};
	vector<int> nums (arr, arr + sizeof(arr) / sizeof(int));
	Solution obj;
	obj.printVec(nums);
	vector<int> ans = obj.getConcatenation(nums);
	obj.printVec(ans);
	return 1;
}
