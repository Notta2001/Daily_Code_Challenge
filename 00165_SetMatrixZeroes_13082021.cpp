#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        vector<vector<int>> setZeroes(vector<vector<int>>& matrix) {
            int row = 0;
            int col = 0;
            
            for(int i = 0; i < matrix.size(); ++i)
                if(matrix[i][0] == 0) {
                    row = 1;
                    break;
                }
            
            for(int i = 0; i < matrix[0].size(); ++i)
                if(matrix[0][i] == 0) {
                    col = 1;
                    break;
                }
            
            for(int i = 1; i < matrix.size(); ++i)
                for(int j = 1; j < matrix[0].size(); ++j)
                    if(matrix[i][j] == 0){
                        matrix[0][j] = 0;
                        matrix[i][0] = 0;
                    }
            
            for(int i = 1; i < matrix.size(); ++i) 
                if(matrix[i][0] == 0)
                    for(int j = 0; j < matrix[i].size(); ++j)
                        matrix[i][j] = 0;

            for(int i = 1; i < matrix[0].size(); i++)
                if(matrix[0][i] == 0)
                    for(int j = 0; j < matrix.size(); j++)
                        matrix[j][i] = 0;

            if(col == 1) 
                for(int i = 0; i < matrix[0].size(); ++i)
                    matrix[0][i] = 0;
            
            if(row == 1)
                for(int i = 0; i < matrix.size(); ++i)
                    matrix[i][0] = 0;

            return matrix;
        }

        void printMatrix(vector<vector<int>>& matrix){
            for(int i = 0; i < matrix.size(); ++i) {
                for(int j = 0; j < matrix[0].size(); ++j)
                    cout << " " << matrix[i][j] << " ";
                cout << endl;
            }
        }
};

int main () {
    int arr[3][3]= {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    vector<vector<int>> matrix(3, vector<int>(3, 0));
    for(int i = 0; i < 3; ++i) 
        for(int j = 0; j < 3; ++j)
            matrix[i][j] = arr[i][j];

    Solution obj;
    obj.printMatrix(matrix);
    obj.setZeroes(matrix);
    cout << "---------------------------" << endl;
    obj.printMatrix(matrix);

    return 1;
}

// https://leetcode.com/problems/set-matrix-zeroes/