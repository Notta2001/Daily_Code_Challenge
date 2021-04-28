//Dynamic Algorithm
#include<iostream>
#include<vector>
using namespace std;

int uniquePathsWithObstacles(const vector<vector<int> > &obstacleGrid){
	int rows = obstacleGrid.size();
	int cols = obstacleGrid[0].size();
	int dp[rows][cols];
	bool flag = false;
	
	// Fill 1st row
	// Remember from the obstacle to the right you can't move anyone more step
	for(int i = 0; i < cols; ++i){
		if(flag || obstacleGrid[0][i]){
			flag = true;
			dp[0][i] = 0;
		}
		else{
			dp[0][i] = 1;
		}
	}
	
	// Fill 1st column
	// Remember that from the obstacle to the bottom you can't move anyone more step
	flag = false;
	for(int i = 0; i < rows; ++i){
		if(flag || obstacleGrid[i][0]){
			flag = true;
			dp[i][0] = 0;
		}
		else{
			dp[i][0] = 1;
		}
	}
	
	for(int i = 1; i < rows; ++i){
		for(int j = 1; j < cols; ++j){
			if(obstacleGrid[i][j] == 1){
				dp[i][j] = 0;
			}
			else{
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
			}
		}
	}
	return dp[rows-1][cols-1];
}	

int main(){
	int a[3][3] = {{0,0,0},{0,1,0},{0,0,0}};
	vector<vector<int> > v;
	for(int i = 0; i < 3; ++i){
		vector<int> b(&a[i][0], &a[i][0] + 3);
		v.push_back(b);
	}
	cout << uniquePathsWithObstacles(v) << endl;
	return 0;
}
