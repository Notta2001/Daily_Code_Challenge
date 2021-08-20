#include<iostream>
#include<vector>
using namespace std;

/*
    Square row: sr = r/3
    Square col: sc = c/3
    Square position: sr*3 + sc

*/
class Solution {
    public:
        int getBit(int x, int k) {
            return (x >> k) & 1;
        }

        bool isValidSudoku(vector<vector<char>>& board) {
            int N = 9;
            vector<int> rows(N), cols(N), squares(N);

            for (int r = 0; r < N; r++) {
                for (int c = 0; c < N; c++) {
                    if (board[r][c] == '.') continue;
                    int val = board[r][c] - '0';
                    int sPos = (r / 3) * 3 + (c / 3);
                    if (getBit(rows[r], val) || getBit(cols[c], val) || getBit(squares[sPos], val))
                        return false;
                    rows[r] |= 1 << val;
                    cols[c] |= 1 << val;
                    squares[sPos] |= 1 << val;
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