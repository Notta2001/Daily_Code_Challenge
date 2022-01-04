#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int minDistance(string &word1, string &word2){
	int n = word1.length();
	int m = word2.length();
	int dp[n+1][m+1];
	
	// The matrix will store how many characters you need to remove to make word1[:i] equal word2[:j]
	// Each word will start when it is empty
	for(int i = 0; i <= n; ++i){
		for(int j = 0; j <= m; ++j){
			if(i == 0 || j == 0){
				dp[i][j] = i + j;
			}
			else if(word1[i-1] == word2[j-1]){
				dp[i][j] = dp[i-1][j-1];
			}
			else{
				dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	return dp[n][m];
}

int main(){
	string word1 = "thang";
	string word2 = "agc";
	cout << minDistance(word1, word2);
	return 0;
}

// https://leetcode.com/problems/delete-operation-for-two-strings/