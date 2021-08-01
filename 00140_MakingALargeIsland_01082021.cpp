#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
using namespace std;

class Solution{
	private: 
		int count = 0;
	public:
		void dfs(vector<vector<int> >&grid, int i, int j, int island_Id) {
			if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1)
				return;
			
			if(grid[i][j] = 1){
				grid[i][j] = island_Id;
				count ++;
				
				dfs(grid, i + 1, j, island_Id);
				dfs(grid, i - 1, j, island_Id);
				dfs(grid, i, j - 1, island_Id);
				dfs(grid, i, j + 1, island_Id);
			}
		}
		
		void printMax(vector<vector<int> > &grid){
			int m = grid.size();
			int n = grid[0].size();
			
			for(int i = 0; i < m; ++i){
				for(int j = 0; j < n; ++j){
					cout << " " << grid[i][j] << " ";
				}
				cout << endl;
			}
		}
		
		int largestIsland(vector<vector<int> >& grid) {
			if(grid.size() == 0) return 0;
			int m = grid.size();
			int n = grid[0].size();
			
			int maxval = 0;
			int island_Id = 2;
			int temp[5] = {-1, 0, 1, 0, -1};
			map<int, int>mp;

			printMax(grid);
			cout << "-------------------------" << endl;
			
			for(int i = 0; i < m; ++i){
				for(int j = 0; j < n; ++j){
					if(grid[i][j] == 1){
						dfs(grid, i, j, island_Id);
						maxval = max(maxval, count);
						mp[island_Id] = count;
						count = 0;
						island_Id ++;
					}		
				}
			}
			
			printMax(grid);
			
			for(int i = 0; i < m; ++i){
				for(int j = 0; j < n; ++j){
					if(grid[i][j] == 0) {
						set<int> st;
						
						for(int k = 0; k < 4; ++k){
							int xx = i + temp[k], yy = j + temp[k+1];
							if(xx >= 0 && xx < m && yy >= 0 && yy < n && grid[xx][yy] != 0) {
								st.insert(grid[xx][yy]);
							}
						}
						
						int sum = 1;
						
						for (set<int>::iterator itr = st.begin(); itr != st.end(); itr++){
        					sum += mp[*itr];
    					}		
    					maxval = max(maxval, sum);
					}
				}
			}
			
			return maxval;
		}
		
};

int main(){
	vector<vector<int> > grid(3, vector<int>(5, 0));
	grid[0][1] = grid[0][3] = grid[1][0] = grid[1][1] = grid[1][4] = grid[2][2] = grid[2][3] = 1;
	Solution obj;
	int ans = obj.largestIsland(grid);
	cout << "Answer: " << ans;
	
	return 1;
}

//https://leetcode.com/problems/making-a-large-island/
