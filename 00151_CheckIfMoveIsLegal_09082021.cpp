#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        bool checkMove(vector<vector<char>>& s, int r, int c, char color) {
            s[r][c] = color;
            int dx[8] = {0, 1, -1, 0, 1, 1, -1, -1};
            int dy[8] = {1, 0, 0, -1, -1, 1, -1, 1};

            for(int i = 0; i < 8; ++i) {
                for(int j = 1; ; ++j){
                    int nr = r + dx[i]*j;
                    int nc = c + dy[i]*j;

                    if(nr < 0 || nc < 0 || nr >= 8 || nc >= 8) break;

                    if(s[nr][nc] == '.') break;
                    if(s[nr][nc] == color) {
                        if(j > 1) return true;
                        break;
                    }
                }
            }

            return false;
        }
};

int main () {
    char arr[8][8] = {{'.', '.', '.', 'B', '.', '.', '.', '.'},
                      {'.', '.', '.', 'W', '.', '.', '.', '.'},
                      {'.', '.', '.', 'W', '.', '.', '.', '.'},
                      {'.', '.', '.', 'W', '.', '.', '.', '.'},
                      {'W', 'B', 'B', '.', 'W', 'W', 'W', 'B'},
                      {'.', '.', '.', 'B', '.', '.', '.', '.'},
                      {'.', '.', '.', 'B', '.', '.', '.', '.'},
                      {'.', '.', '.', 'W', '.', '.', '.', '.'}};

    vector<vector<char>> board(8, vector<char>(8, 0));
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j){
            cout << " " << arr[i][j] << " ";
            board[i][j] = arr[i][j];
        }
        cout << endl;
    }

    Solution obj;
    cout << obj.checkMove(board, 4, 3, 'B') << endl;

    return 1;
}

//https://leetcode.com/problems/check-if-move-is-legal/