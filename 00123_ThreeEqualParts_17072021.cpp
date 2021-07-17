#include<iostream>
#include<vector>
using namespace std;

class Solution {
	public:
		vector<int> threeEqualParts(vector<int>& v){
			int n = v.size();
			vector<int> res;
			vector<int> ones;
			for(int i = 0; i < n; ++i)
				if(v[i]) ones.push_back(i);
			int cnt = ones.size();
			if(!cnt){
				res.push_back(0);
				res.push_back(n-1);
				return res;
			}; // array consists only 0 elements
			if(cnt % 3){
				res.push_back(-1);
				res.push_back(-1);
				return res;
			}; // array need consist 3*n 1 because we need three equal parts
			int x = ones[0], y = ones[cnt/3], z = ones[cnt/3*2]; // we need devide three equal number of 1 into 3 parts to make it able to be equal
			cout << x << " " << y << " " << z << endl;
			while (z < n && v[x] == v[y] && v[x] == v[z]) x++, y++, z++;
			// In general, first we devide ones into three parts begin with 1, then we loop through it to make sure every element in three parts are equal
			if(z == n) {
				res.push_back(x-1);
				res.push_back(y);
				return res;
			};
			
			res.push_back(-1);
			res.push_back(-1);
			return res;
		}
		
		void printRes(vector<int> res, vector<int>& v){
			for(int i = 0; i <= res[0]; ++i){
				cout << v[i] << " ";
			}
			cout << endl;
			for(int i = res[0] + 1; i < res[1]; ++i){
				cout << v[i] << " ";
			}
			cout << endl;
			for(int i = res[1]; i < v.size(); ++i){
				cout << v[i] << " ";
			}
		}	
};

int main(){
	int arr[] = {1,0,1,0,1};
	vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
	Solution obj;
	vector<int> res;
	res = obj.threeEqualParts(nums);
	obj.printRes(res, nums);
}

//https://leetcode.com/problems/three-equal-parts/
