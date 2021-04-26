#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void rotate(vector<vector<int> >&matrix){
	int n = matrix.size();
	for(int i = 0; i < n; ++i){
		for(int j = i + 1; j < n; ++j){
			swap(matrix[i][j], matrix[j][i]);
		}
	}
	
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n/2; ++j){
			swap(matrix[i][j], matrix[i][n-1-j]);
		}
	}
}

void print(const vector<vector<int> > &matrix){
	int n = matrix.size();
	cout << "--------" << endl;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cout << matrix[i][j];
		}
		cout << endl;
	}
	cout << "--------" << endl;
}

int main(){
	int a[4][4] = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
	vector<vector<int> > matrix(4);
	for(int i = 0; i < 4; ++i){
		matrix[i].assign(&a[i][0], &a[i][3]);
	}
	print(matrix);
	rotate(matrix);
	print(matrix);
	return 0;
}

