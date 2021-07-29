#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution{
	public:
		vector<vector<int> > updateMatrix(vector<vector<int> > & mat){
			int x[] = {0, 1, 0, -1};
			int y[] = {1, 0, -1, 0};
			
			vector<vector<int> > dist (mat.size(), vector<int> (mat[0].size(), -1));
			queue<vector<int> > q;
			
			vector<int> temp(2, 0);
			vector<int> cur(2, 0);
			for(int i = 0; i < mat.size(); ++i){
				for(int j = 0; j < mat[0].size(); ++j){
					if(mat[i][j] == 0){
						temp[0] = i;
						temp[1] = j;
						q.push(temp);
						dist[i][j] = 0;
					}
				}
			}
			
			while(!q.empty()){
				cur = q.front();
				for(int i = 0; i < 4; ++i){
					int cx = cur[0] + x[i];
					int cy = cur[1] + y[i];
					if(cx < 0 || cx == mat.size() || cy < 0 || cy == mat[0].size())
						continue;
					if(dist[cx][cy] == -1){
						dist[cx][cy] = dist[cur[0]][cur[1]] + 1;
						temp[0] = cx;
						temp[1] = cy;
						q.push(temp);
					}
				}
				q.pop();
			}
			return dist;
		}
		
		void printVect(vector<vector<int> >&nums){
			for(int i = 0; i< nums.size(); ++i){
				cout << "[";
				for(int j = 0; j < nums[0].size(); ++j){
					cout << " " << nums[i][j] << " ";
				}
				cout << "]" << endl;
			}
		}
};

int main(){
	Solution obj;
	int arr[][3] = {{0, 0, 0}, {0 ,1, 0}, {1, 1, 1}};
	vector<vector<int> >mat (3, vector<int> (3, 0));
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			mat[i][j] = arr[i][j];
		}
	}
	
	obj.printVect(mat);
	vector<vector<int> > dist = obj.updateMatrix(mat);
	cout << "-----------" << endl;
	obj.printVect(dist);
	
	return 1;
}

//https://leetcode.com/problems/01-matrix/
