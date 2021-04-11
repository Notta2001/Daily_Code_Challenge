#include<iostream>
#include<vector>
using namespace std;

void dfs(const vector<vector<int>> &matrix, int row, int col, int prev, vector<vector<int>> &ocean) {
	if (row < 0 || col < 0 || row >= matrix.size() || col >= matrix[0].size()) {
		return;
	}
	if (matrix[row][col] < prev) {
		return;
	}
	if (ocean[row][col] == -1) {
		return;
	}
	ocean[row][col] = -1;
	dfs(matrix, row - 1, col, matrix[row][col], ocean);
	dfs(matrix, row + 1, col, matrix[row][col], ocean);
	dfs(matrix, row, col - 1, matrix[row][col], ocean);
	dfs(matrix, row, col + 1, matrix[row][col], ocean);
}

vector<vector<int>> PacificAtlantic(vector<vector<int>>& matrix) {
	vector<vector<int>> res;
	if (matrix.size() == 0) return res;
	vector<vector<int>> pacific(matrix.size(), vector<int>(matrix[0].size(), 0));
	vector<vector<int>> atlantic(matrix.size(), vector<int>(matrix[0].size(), 0));
	for (int col = 0; col < matrix[0].size(); ++col) {
		dfs(matrix, 0, col, INT_MIN, pacific);
		dfs(matrix, matrix.size() - 1, col, INT_MIN, atlantic);
	}
	for (int row = 0; row < matrix.size(); ++row) {
		dfs(matrix, row, 0, INT_MIN, pacific);
		dfs(matrix, row, matrix[0].size() - 1, INT_MIN, atlantic);
	}
	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = 0; j < matrix[0].size(); ++j) {
			if (pacific[i][j] == -1 && pacific[i][j] == atlantic[i][j]) {
				res.push_back({ i, j });
			}
		}
	}
	return res;
}


int main() {
	vector<vector<int>> res; 
	vector<vector<int>> matrix;
	matrix.push_back({ 1, 2, 2, 3, 5 });
	matrix.push_back({ 3, 2, 3, 4, 4 });
	matrix.push_back({ 2, 4, 5, 3, 1 });
	matrix.push_back({ 6, 7, 1, 4, 5 });
	matrix.push_back({ 5, 1, 1, 2, 4 });
	res = PacificAtlantic(matrix);
	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j) {
			cout << res[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}