#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct point {
	int x, y, c;
};

class Solution {
	public : 
		int v[1005][1005];
		
		int nearestExit (vector<vector<char> >&ma, vector<int> &e) {
			queue<point> q;
			int n = ma.size();
			int m = ma[0].size();
			point p;
			p.x = e[0];
			p.y = e[1];
			p.c = 0;
			q.push(p);
			v[e[0]][e[1]] = 1;
			
			while (!q.empty()) {
				point temp = q.front();
				q.pop();
				int a[] = {1, 0, 0, -1};
				int b[] = {0, -1, 1, 0};
				for(int i = 0; i < 4; ++i){
					int nx = temp.x + a[i], ny = temp.y + b[i];
					if (temp.c >= 1 && (nx < 0 || nx >= n || ny < 0 || ny >= m)) return temp.c;
				
					if (nx >= 0 && nx < n && ny >= 0 && ny < m && ma[nx][ny] != '+' && !v[nx][ny]){
						point np;
						np.x = nx;
						np.y = ny;
						np.c = temp.c + 1;
						q.push(np);
						v[nx][ny] = 1;
					}
				}
			}
			
			return -1;
		}
};

int main () {
	vector<int> entrance;
	entrance.push_back(1);
	entrance.push_back(2);
	char maze[3][4] = {{'+', '+', '.', '+'}, {'.', '.', '.', '+'}, {'+', '+', '+', '.'}};
	cout << '.' ;
	
	vector<vector<char> > ma(3, vector<char>(4, 0));
	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 4; ++j){
			ma[i][j] = maze[i][j];
		}
	}

	Solution obj;
	cout << obj.nearestExit(ma, entrance);
}

//https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/
