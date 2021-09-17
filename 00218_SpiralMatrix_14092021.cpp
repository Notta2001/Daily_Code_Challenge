#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector<int> result;
            int rowBegin, colBegin, rowEnd, colEnd;
            rowBegin = colBegin = 0;
            rowEnd = matrix.size() - 1;
            colEnd = matrix[0].size() - 1;
            while(rowBegin <= rowEnd && colBegin <= colEnd) {
                for(int i = colBegin; i <= colEnd; ++i) 
                    result.push_back(matrix[rowBegin][i]);
                
                for(int i = ++rowBegin; i <= rowEnd; ++i) 
                    result.push_back(matrix[i][colEnd]);

                for(int i = --colEnd; rowBegin <= rowEnd && i >= colBegin; --i)
                    result.push_back(matrix[rowEnd][i]);

                for(int i = --rowEnd; colBegin <= colEnd && i >= rowBegin; --i)
                    result.push_back(matrix[i][colBegin]);
                
                colBegin ++;
            }
            return result;
        }

        void printMatrix(vector<vector<int>>& matrix) {
            for(vector<int> row : matrix) {
                cout << "[";
                for(int num : row)
                    cout << " " << num << " ";
                cout << "]" << endl;
            }
        }
};

int main () {
    vector<vector<int>> matrix;
    matrix.push_back({1, 2, 3, 4});
    matrix.push_back({5, 6, 7, 8});
    matrix.push_back({9, 10, 11, 12});

    Solution obj;
    obj.printMatrix(matrix);
    vector<int> result = obj.spiralOrder(matrix);
    vector<vector<int>> results;
    results.push_back(result);
    obj.printMatrix(results);
    return 1;
}