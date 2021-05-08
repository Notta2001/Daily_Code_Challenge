#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int longestCommonSubsquence(string &word1, string &word2){
	int n = word1.length();
	int m = word2.length();
	int dp[n+1][m+1];
	
	// Dynamic Programming
	for(int i = 0; i <= n; ++i){
		for(int j = 0; j <= m; ++j){
			if(i == 0 || j == 0){
				dp[i][j] = 0;
			}
			else if(word1[i-1] == word2[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	return dp[n][m];
}

int main(){
	string word1 = "thang";
	string word2 = "tahbacndg";
	cout << longestCommonSubsquence(word1, word2);
	return 0;
}
