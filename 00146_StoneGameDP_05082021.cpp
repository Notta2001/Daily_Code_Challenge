#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

/*	
	Alex and Lee play a game with piles of stones. There are an even number of piles arranged in a row, and each
pile has positive integer number of stones (piles[i])
	The objective of the game is to end with the most stones. The total number of stones is odd, so there are no ties.
	Alex and Lee take turns, with Alex starting first. Each turn, a player takes the entire pile of stones from either the
beginning or the end of the row. This continues until there are no more piles left, at which point the person with
the most stones wins.
	Assuming Alex and Lee play optimally, return True if and only if Alex wins the game.
*/

class Solution {
	public :
		int dp[501][501];
		int help(int i, int j, vector<int> &piles) {
			if(i > j) return 0;
			if(dp[i][j] != -1) return dp[i][j];
			return dp[i][j] = max(piles[i] - help(i+1, j, piles), piles[j] - help(i, j-1, piles));
		}
		bool stoneGame(vector<int> &piles) {
			int n = piles.size();
			memset(dp, -1, sizeof dp);
			return help(0, n-1, piles) > 0;
		}
};

int main () {
	int arr[] = {5, 3, 4, 5};
	vector<int> piles (arr, arr + sizeof(arr)/sizeof(int));
	
	Solution obj;
	cout << obj.stoneGame(piles);
	
	return 1;
}

// https://leetcode.com/problems/stone-game/
