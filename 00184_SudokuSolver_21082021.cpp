#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        int N = 9;
        vector<string> rows = vector<string>(9, "000000000");
        vector<string> cols = vector<string>(9, "000000000");
        vector<string> squares = vector<string>(9, "000000000");
        bool solved = false;

        void sudoku(int row, int col, vector<vector<char>>& board) {
            if(solved)
                return;
            
            if(row == 9) {
                solved = true;
                return;
            }

            if(col == 9) {
                sudoku(row + 1, 0, board);
                return;
            }

            if(board[row][col] != '.'){
                sudoku(row, col + 1, board);
                return;
            }

            for(int i = 1; i <= 9; ++i) {
                int sPos = (row / 3) * 3 + (col / 3);
                if(rows[row][i-1] != '1' && cols[col][i-1] != '1' && squares[sPos][i-1] != '1'){
                    board[row][col] = i + '0';
                    rows[row][i-1] = '1';
                    cols[col][i-1] = '1';
                    squares[sPos][i-1] = '1';
                    sudoku(row, col + 1, board);
                    if(!solved) {
                        board[row][col] = '.';
                        rows[row][i-1] = '0';
                        cols[col][i-1] = '0';
                        squares[sPos][i-1] = '0';
                    }      
                }
            }
        }

        void solveSudoku(vector<vector<char>>& board) {
            for(int r = 0; r < 9; ++r) {
                for(int c = 0; c < 9; ++c) {
                    if(board[r][c] == '.')
                        continue;
                    int val = board[r][c] - '0';
                    int sPos = (r / 3) * 3 + (c / 3);
                    rows[r][val-1] = '1';
                    cols[c][val-1] = '1';
                    squares[sPos][val-1] = '1';
                }
            }

            sudoku(0, 0, board);
        }

        void printBoard(vector<vector<char>>& board){
            for(int i = 0; i < 9; ++i){
                for(int j = 0; j < 9; ++j)
                    cout << " " << board[i][j] << " ";
                cout << endl;
            }
            cout << " -------------------------" << endl;
        }
};

int main () {
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
    cout << " -------------------------" << endl;

    Solution obj;
    obj.printBoard(board);
    obj.solveSudoku(board);
    obj.printBoard(board);

    return 1;
}

//https://leetcode.com/problems/sudoku-solver/