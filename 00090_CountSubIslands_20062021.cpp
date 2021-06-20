#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int n, m;
    
    void dfs(vector<vector<int> >& grid, int x, int y, int c) {
        if (x < 0 || y < 0 || x >= n || y >= m) return;
        if (grid[x][y] != 1) return;
        grid[x][y] = c;
        for (int i = 0; i < 4; ++i) dfs(grid, x + dx[i], y + dy[i], c);
    }
    
    void check(vector<vector<int> >& grid1, vector<vector<int> >& grid2, int x, int y, int c, bool& f) {
        if (x < 0 || y < 0 || x >= n || y >= m) return;
        if (grid2[x][y] != 1) return;
        grid2[x][y] = 0;
        if (grid1[x][y] != c) f = 0;
        for (int i = 0; i < 4; ++i) check(grid1, grid2, x + dx[i], y + dy[i], c, f);
    }
    
    int countSubIslands(vector<vector<int> >& grid1, vector<vector<int> >& grid2) {
        n = grid1.size();
        m = grid1[0].size();
        int cur = 2;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid1[i][j] == 1)
                    dfs(grid1, i, j, cur);
        int ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid2[i][j] == 1) {
                    bool flag = grid1[i][j];
                    check(grid1, grid2, i, j, grid1[i][j], flag);
                    ans += flag;
                }
        return ans;
    }
};

int main(){
	int arr1[5][5] = {{1,1,1,0,0},{0,1,1,1,1},{0,0,0,0,0},{1,0,0,0,0},{1,1,0,1,1}};
	int arr2[5][5] = {{1,1,1,0,0},{0,0,1,1,1},{0,1,0,0,0},{1,0,1,1,0},{0,1,0,1,0}};
	vector<vector<int> >grid1;
	vector<vector<int> >grid2;
	for(int i = 0; i < 5; ++i){
		vector<int> a1(arr1[i], arr1[i] + sizeof(arr1[i]) / sizeof(int));
		vector<int> a2(arr2[i], arr2[i] + sizeof(arr2[i]) / sizeof(int));
		grid1.push_back(a1);
		grid2.push_back(a2);
	}
	Solution obj;
	cout << obj.countSubIslands(grid1, grid2);
}

//https://leetcode.com/problems/count-sub-islands/
