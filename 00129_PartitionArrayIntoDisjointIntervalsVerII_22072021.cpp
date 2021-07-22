#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution  {
	public:
		int partitionDisjoint(vector<int> &nums){
			vector<int> right (nums.size(), 0);
			
			int mn = INT_MAX;
			for(int i = nums.size()-1; i >= 0; --i){
				mn = min(mn, nums[i]);
				right[i] = mn;
			}
			
			int mx = INT_MIN;
			for(int i = 0; i < nums.size(); ++i){
				mx = max(mx, nums[i]);
				if(mx <= right[i+1]){
					return i+1;
				}
			}
			return 1;
		}
		
		void print(int index, vector<int> &nums){
			cout << "[";
			for(int i = 0; i < index; ++i){
				cout << " " << nums[i] << " ";
			}
			cout << "]" << endl;
			
			cout << "[";
			for(int i = index; i < nums.size(); ++i){
				cout << " " << nums[i] << " ";
			}
			cout << "]" << endl;
		}
};

int main(){
	int arr[] = {32, 57, 24, 19, 0, 24, 49, 67, 87, 87};
	vector<int> nums (arr, arr + sizeof(arr)/sizeof(int));
	Solution obj;
	int index = obj.partitionDisjoint(nums);
	cout << index << endl;
	obj.print(index, nums);
	
	return 1;
}
