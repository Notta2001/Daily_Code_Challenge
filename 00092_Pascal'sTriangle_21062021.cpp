#include<iostream>
#include<vector>
using namespace std;

class Solution{
	public:
		vector<vector<int> > generate(int numRows){
			vector<vector<int> > ans;
			for(int i = 0; i < numRows; ++i){
				vector<int> temp(i+1, 1);
				for(int j = 1; j < i; ++j){
					temp[j] = ans[i-1][j] + ans[i-1][j-1];
				}
				ans.push_back(temp);
			}
			return ans;
		}
		
		void printVector(vector<vector<int> > &ans){
			for(int i = 0; i < ans.size(); ++i){
				cout << "[" ;
				for(int j = 0; j < ans[i].size(); ++j){
					cout << " " << ans[i][j] << " " ;
				}
				cout << "]" << endl;
			}
		}
};

int main(){
	Solution obj;
	vector<vector<int> > ans = obj.generate(20);
	obj.printVector(ans);
	return 0;
}

//https://leetcode.com/problems/pascals-triangle/

