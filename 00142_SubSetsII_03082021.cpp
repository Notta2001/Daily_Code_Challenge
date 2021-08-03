#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
	public :
		vector<vector<int> >subsetsWithDup(vector<int> &nums){
			sort(nums.begin(), nums.end());
			
			vector<vector<int> >res;
			vector<int> curr;
			res.push_back(curr);
			int size;
			
			for(int i = 0; i < nums.size(); ++i){
				size = res.size();
				
				for(int j = 0; j < size; ++j){
					curr = res[j];
					curr.push_back(nums[i]);
					if(find(res.begin(), res.end(), curr) == res.end())
						res.push_back(curr);
				}
			}
			
			return res;
		}
		
		void printAns(vector<vector<int> >& res){
			cout << "[";
			for(int i = 0; i < res.size(); ++i){
				cout <<"[";
				for(int j = 0; j < res[i].size(); ++ j){
					cout << " " << res[i][j] << " "; 
				}
				cout <<"]";
			}
			cout << "]" << endl;
		}
};

int main(){
	int arr[] = {1, 2, 3};
	vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
	
	Solution obj;
	vector<vector<int> > res = obj.subsetsWithDup(nums);
	obj.printAns(res);
	
	return 1;
}
