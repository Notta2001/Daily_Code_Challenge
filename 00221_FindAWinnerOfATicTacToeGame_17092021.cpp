#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        string tictactoe(vector<vector<int>>& moves) {
            int winner = findWinner(moves);
            if(winner < 2) 
                if(winner == 0)
                    return "A";
                else
                    return "B";
            if(moves.size() < 9) 
                return "Pending";
            else    
                return "Draw";
        }

    private:
        void printMatrix(vector<vector<int>>& mat) {
            for(auto row : mat) {
                cout << "[";
                for(int ele : row)
                    cout << " " << ele << " ";
                cout << "]" << endl;   
            }
            cout << "----------------------------" << endl;
        }

        int findWinner(vector<vector<int>>& moves) {
            vector<vector<int>> mat(3, vector<int>(3, -1));
            for(int i = 0; i < moves.size(); ++i) 
                mat[moves[i][0]][moves[i][1]] = i%2;
            printMatrix(mat);
            for(int i = 0; i < 3; ++i){
                if(mat[i][0] != -1 && mat[i][0] == mat[i][1] && mat[i][1] == mat[i][2]) return (mat[i][0] == 0) ? 0 : 1;
                if(mat[0][i] != -1 && mat[0][i] == mat[1][i] && mat[1][i] == mat[2][i]) return (mat[0][i] == 0) ? 0 : 1;
            }
            if(mat[0][0] != -1 && mat[0][0] == mat[1][1] && mat[1][1] == mat[2][2]) return (mat[0][0] == 0) ? 0 : 1;
            else if(mat[0][2] != -1 && mat[0][2] == mat[1][1] && mat[1][1] == mat[2][0]) return (mat[0][2] == 0) ? 0 : 1;
            return 2;
        }

        
};

int main () {
    vector<vector<int>> moves;
    moves.push_back({0, 0});
    moves.push_back({1, 1});
    moves.push_back({2, 0});
    moves.push_back({1, 0});
    moves.push_back({1, 2});
    moves.push_back({2, 1});
    moves.push_back({0, 1});
    moves.push_back({0, 2});
    moves.push_back({2, 2});

    Solution obj;
    cout << obj.tictactoe(moves);

    return 1;
}

//https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/