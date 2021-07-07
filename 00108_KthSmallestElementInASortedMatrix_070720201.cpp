#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
	public: 
		int kthSmallest(vector<vector<int> > &matrix, int k){
			int r = matrix.size();
			int c = matrix[0].size();
			priority_queue<int> pq;
			for(int i = 0; i < r; ++i){
				for(int j = 0; j < c; ++j){
					pq.push(matrix[i][j]);
					if(pq.size() > k){
						pq.pop();
						break;
					} 
				}
			}
			return pq.top();
		}
		
		void printVect(vector<vector<int> >&matrix){
			int r = matrix.size();
			int c = matrix[0].size();
			
			cout << "[" ;
			for(int i = 0; i < r; ++i){
				cout << "[";
				for(int j = 0; j < c; ++j){
					cout << " " << matrix[i][j] << " ";
				}
				cout << "]";
			}
			cout << "]" << endl;
		}
};


int main(){
	int arr[3][3] = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
	vector<vector<int> >matrix (3, vector<int>());
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			matrix[i].push_back(arr[i][j]);
		}
	}
	Solution obj;
	obj.printVect(matrix);
	cout << obj.kthSmallest(matrix, 8);
	return 1;
}


//https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
