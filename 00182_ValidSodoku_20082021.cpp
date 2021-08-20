#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

/*
    Square row: sr = r/3
    Square col: sc = c/3
    Square position: sr*3 + sc

*/
class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
            int N = 9;
            unordered_set<char> rowSet[N];
            unordered_set<char> colSet[N];
            unordered_set<char> squareSet[N];

            for(int r = 0; r < N; ++r) {
                for(int c = 0; c < N; ++c) {
                    char val = board[r][c];
                    if(val == '.')
                        continue;
                    int sPos = (r/3)*3 + c/3;
                    if(rowSet[r].count(val) || colSet[c].count(val) || squareSet[sPos].count(val))
                        return false;
                    rowSet[r].insert(val);
                    colSet[c].insert(val);
                    squareSet[sPos].insert(val);
                }
            }
            return true;
        }

        void printBoard(vector<vector<char>>& board){
            for(int i = 0; i < 9; ++i){
                for(int j = 0; j < 9; ++j)
                    cout << " " << board[i][j] << " ";
                cout << endl;
            }
            cout << "---------------------------------------" << endl;
        }
};

int main() {
    int arr[9][9] = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                     {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                     {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                     {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                     {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                     {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                     {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                     {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                     {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    vector<vector<char>> board(9, vector<char>(9, '.'));
    for(int i = 0; i < 9; ++i)
        for(int j = 0; j < 9; ++j)
            board[i][j] = arr[i][j];

    Solution obj;
    obj.printBoard(board);
    cout << "Valid: " << obj.isValidSudoku(board) << endl;

    return 1;
}
//https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/615/week-3-august-15th-august-21st/3904/