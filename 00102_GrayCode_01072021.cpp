#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution{
	public:
		vector<int> grayCode(int n){
			int count = 2;
			int max = 1;
			while(n > 0){
				max *= 2;
				n --;
			}
			
			vector<int> res;
			res.push_back(0);
			res.push_back(1);
			
			int index = 1;
			while(count < max){
				if(index % 2 == 1){
					res.push_back(res[index] * 2 + 1);
					res.push_back(res[index] * 2);
				}
				else{
					res.push_back(res[index] * 2);
					res.push_back(res[index] * 2 + 1);
				}

				count += 2;
				index ++;
			}
			
			return res;
		}
		
		void printVec(vector<int> &res){
			cout << "[";
			for(int i = 0; i < res.size(); ++i){
				cout << " " << res[i] << " ";
			}
			cout << "]"<< endl;
		}
};

int main(){
	Solution obj;
	vector<int> ans1 = obj.grayCode(10);
	obj.printVec(ans1);
	vector<int> ans2 = obj.grayCode(5);
	obj.printVec(ans2);
	return 1;
}

//https://leetcode.com/problems/gray-code/

