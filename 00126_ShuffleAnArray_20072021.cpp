#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
	public:
	vector<int> arr;
	vector<int> ori;
	
	Solution(vector<int>& nums){
		ori = nums;
		arr = nums;
	}
	
	/** Resets the array to its original configuration and return it. */
	vector<int> reset(){
		return ori;
	}
	
	/** Returns a random shuffling of the array. */
	vector<int> shuffle(){
		// Way 1: use algorithm library
		//next_permutation(arr.begin(), ar.end());
		//return arr;
		
		// Way 2: use random function
		int random;
		int tmp;
		for(int i = 0; i < arr.size(); ++i){
			random = rand() % (arr.size()-i);
			if(random != arr.size()-i-1){
				tmp = arr[random];
				arr[random] = arr[arr.size()-i-1];
				arr[arr.size()-i-1] = tmp;
			}
		}
		
		return arr;
	}
	
	void printVector(vector<int> nums){
		cout << "[";
		for(int i = 0; i < nums.size(); ++i){
			cout << " " << nums[i] << " ";
		}
		cout << "]" << endl;
	}
};

int main(){
	int arr[] = {1, 2, 3, 4, 5};
	vector<int> nums (arr, arr + sizeof(arr)/sizeof(int));
	Solution obj(nums);
	obj.printVector(obj.reset());
	obj.printVector(obj.shuffle());
	obj.printVector(obj.shuffle());
	obj.printVector(obj.shuffle());
	obj.printVector(obj.shuffle());
		
	return 1;
}

