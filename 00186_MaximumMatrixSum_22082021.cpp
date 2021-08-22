#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        long long maxMatrixSum(vector<vector<int>>& matrix) {
            long long count_nev = 0, ans = 0, n = matrix.size(), minn=10000;
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j) {
                    ans += abs(matrix[i][j]);
                    if(matrix[i][j] < 0)
                        count_nev += 1;
                    minn = (minn < abs(matrix[i][j])) ? minn : abs(matrix[i][j]);
                }
            if(count_nev%2)
                return ans - 2*minn;
            else
                return ans;
        }

        void printMatrix(vector<vector<int>>& matrix) {
            for(int i = 0; i < matrix.size(); ++i){
                for(int j = 0; j < matrix.size(); ++j)
                    cout << " " << matrix[i][j] << " ";
                cout << endl;
            }
        }
};

int main() {
    vector<vector<int>> matrix;
    matrix.push_back({1, 2, 3});
    matrix.push_back({-1, -2, -3});
    matrix.push_back({1, 2, 3});

    Solution obj;
    obj.printMatrix(matrix);
    cout << obj.maxMatrixSum(matrix) << endl;

    return 1;
}

//https://leetcode.com/problems/maximum-matrix-sum/