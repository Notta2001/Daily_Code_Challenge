#include<iostream>
#include<vector>
using namespace std;

class Solution {
	public:
		int partitionDisjoint(vector<int> &nums){
			int minNum = nums[0];
			int maxNum = nums[0];
			int index = 0;
			
			for(int i = 1; i < nums.size()-1; ++i){
				cout << minNum << " " << maxNum << endl;
				if(nums[i] < minNum){
					index = i;
					minNum = maxNum;
				}
				maxNum = max(nums[i], maxNum);
			}
		
			return index+1;
		}
		
		void print(int index, vector<int> &nums){
			cout << "[";
			for(int i = 0; i < index; ++i){s
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
	obj.print(index, nums);
	
	return 1;
}
