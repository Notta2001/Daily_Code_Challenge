#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        int orderOfLargestPlusSign(int n, vector<vector<int>>&mines) {
            vector<vector<bool>> isMine(n, vector<bool>(n, false));
            int ans = 0;
            for(int i = 0; i < mines.size(); ++i)
                isMine[mines[i][0]][mines[i][1]] = true;
            for(int r = 0; r < n; ++r) {
                for(int c = 0; c < n; ++ c) {
                    int plusSignSize = dpMaxArm(n, isMine, r, c, 0);
                    for(int d = 1; d < 4; ++d)
                        plusSignSize = min(plusSignSize, dpMaxArm(n, isMine, r, c, d));
                    ans = max(ans, plusSignSize);
                }
            }
            return ans;
        }

        int DIR[5] = {0, 1, 0, -1, 0};
        int memo[500][500][4] = {};
        int dpMaxArm(int n, vector<vector<bool>>& isMine, int r, int c, int d) {
            if(r < 0 || r >= n || c < 0 || c >= n || isMine[r][c]) return 0;
            if(memo[r][c][d] != 0) return memo[r][c][d];
            return memo[r][c][d] = dpMaxArm(n, isMine, r + DIR[d], c + DIR[d+1], d) + 1;
        }
};

int main () {
    vector<int> mine;
    mine.push_back(4);
    mine.push_back(2);
    vector<vector<int>> mines;
    mines.push_back(mine);

    Solution obj;
    cout << obj.orderOfLargestPlusSign(5, mines) << endl;

    return 1;
}

//https://leetcode.com/problems/largest-plus-sign/