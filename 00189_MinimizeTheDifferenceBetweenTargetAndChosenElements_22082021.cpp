#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        int minimizeTheDifference(vector<vector<int>>& mat, int target) {
            int m = mat.size(), n = mat[0].size();
            vector<vector<int>> mem(m, vector<int>(target + 1, INT_MAX));
            vector<int> minSum(m + 1, 0);
            for(int i = m - 1; i >= 0; i--){
                int minVal = INT_MAX;
                for(int num : mat[i]){
                    minVal = min(minVal, num);
                }
                minSum[i] = minSum[i+1] + minVal;
            }
            return dfs(mat, 0, target, minSum, mem);
        }
        
        void printMatrix(vector<vector<int>>& mat) {
            for(int i = 0; i < mat.size(); ++i) {
                for(int j = 0; j < mat[0].size(); ++j) {
                    cout << " " << mat[i][j] << " ";
                }
                cout << endl;
            }
        }
    private:
        int dfs(const vector<vector<int>>& mat, int i, int val, const vector<int>& minSum, vector<vector<int>>& mem){
            if(i >= mat.size()){
                return abs(val);
            }
            if(val <= 0){
                return abs(val - minSum[i]);
            }
            if(mem[i][val] != INT_MAX){
                return mem[i][val];
            }
            int res = INT_MAX;
        for(int j = 0; j < mat[0].size(); j++){
                res = min(res, dfs(mat, i + 1, val - mat[i][j], minSum, mem));
            }
            return mem[i][val] = res;
        }
};

int main () {
    vector<vector<int>> mat;
    mat.push_back({1, 2, 3});
    mat.push_back({4, 5, 6});
    mat.push_back({7, 8, 9});

    Solution obj;
    obj.printMatrix(mat);
    int x = obj.minimizeTheDifference(mat, 13);
    cout << x << endl;

    return 1; 
}

//https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements/