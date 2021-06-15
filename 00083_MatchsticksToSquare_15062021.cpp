#include<iostream>
#include<vector>
using namespace std;

bool solve(int idx, vector <int>& sums, int target, vector <int>& nums){
      if(idx >= nums.size()){
         return sums[0] == sums[1] && sums[1] == sums[2] && sums[2] == target;
      }
      for(int i = 0; i < 4; i++){
         if(sums[i] + nums[idx] > target)continue;
         sums[i] += nums[idx];
         if(solve(idx + 1, sums, target, nums)) return true;
         sums[i] -= nums[idx];
      }
      return false;
   }
   
bool makesquare(vector<int>& nums) {
    if(nums.size() < 4) return false;
    int x = 0;
    for(int i = 0; i < nums.size(); i++){
        x += nums[i];
    }
    if(x % 4) return false;
    sort(nums.rbegin(), nums.rend());
    vector <int> sum(4);
    return solve(0, sum,x / 4, nums);
}

int main(){
	int arr[] = {1,1,2,2,2};
	vector<int> matchsticks(arr, arr + sizeof(arr)/ sizeof(int));
	cout << makesquare(matchsticks);
}
