#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size()-1;
        
        while (right - left + 1 > k) {
            
            if (arr[right] - x < x - arr[left]) left++;
            else right--;
        }
        
        return vector<int>(arr.begin() + left, arr.begin() + right + 1);
        
    }
    
    void printVec(vector<int> &nums){
    	cout << "[" ;
    	for(int i = 0; i < nums.size(); ++i){
    		cout << " " << nums[i] << " " ;
		}
		cout << "]" << endl;	
	}
};

int main (){
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	Solution obj;
	vector<int> arr(array, array + sizeof(array)/ sizeof(int));
	vector<int> nums = obj.findClosestElements(arr, 4, 3);
	obj.printVec(nums);
	return 1;
}
