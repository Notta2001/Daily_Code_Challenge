#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int minSetSize(vector<int>& arr){
    	const int n = arr.size();
		vector<int> m1(100001, 0);
		priority_queue<int> pq;
		
		for(int i = 0; i < n; ++i){
			m1[arr[i]] ++;
		}	
		
		for(int i = 0; i < m1.size(); ++i){
			pq.push(m1[i]);
		}
		
		int c = 0, s = 0;
		
		while(!pq.empty()){
			c += pq.top();
			pq.pop();
			s += 1;
			if(c >= (n/2)){
				break;
			}
		}
		
		return s;
	}
};

int main(){
	Solution obj;
	vector<int> arr;
	arr.push_back(3);
	arr.push_back(3);
	arr.push_back(3);
	arr.push_back(3);
	arr.push_back(5);
	arr.push_back(5);
	arr.push_back(5);
	arr.push_back(2);
	arr.push_back(2);
	arr.push_back(7);
	cout << obj.minSetSize(arr);
	return 1;
}

//https://leetcode.com/problems/reduce-array-size-to-the-half/
