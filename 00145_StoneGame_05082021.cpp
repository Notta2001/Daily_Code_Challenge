#include<iostream>
#include<vector>
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

/*
	Alex can find the sum of elements at odd indicies and even indices.
	Let's say, the sum of elements at odd indices, x > sum of elements at even indicies, y.
	Then, Alex will pick the first element. Now, Lee can choose either element at index 2 or index n, where n is even. After 
selecting any of them, Alex will again have a choice to pickup the element at odd index and Lee will again be forced to take 
an element from an even index. In this way Alex will pickup all the elements at odd indices and making his score x greater than 
Lee's score y.(which we assumed)
	Similarly, we can prove it for the other case.
	So, whichever person starts the game is assured to win if he plays optimally
*/

class Solution {
	public :
		bool stoneGame(vector<int> &piles) {
			return true;
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
