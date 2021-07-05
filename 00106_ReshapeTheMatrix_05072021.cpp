#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > matrixReshape(vector<vector<int> >& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size(), total = m * n;
        if(r * c != total) return mat;
        vector<vector<int> > ans(r, vector<int>(c));
        for(int i = 0; i < total; i++) 
            ans[i / c][i % c] = mat[i / n][i % n];
        return ans;
    }
    
    void printvec(vector<vector<int> > &nums){
    	for(int i = 0; i < nums.size(); ++i){
    		cout << "[" ;
    		for(int j = 0; j < nums[0].size(); ++j){
    			cout << " " << nums[i][j] << " ";
			}
			cout << "]" << endl;
		}
	}
};

int main(){
	vector<vector<int> > nums;
	nums[0].push_back(1);
	nums[0].push_back(2);
	nums[1].push_back(3);
	nums[1].push_back(4);
	Solution obj;
	obj.printvec(nums);
	
	vector<vector<int> > ans;
	ans = obj.matrixReshape(nums, 1, 4);
	obj.printvec(ans);
	
	return 1;
}
