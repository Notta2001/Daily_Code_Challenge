#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
	public:
		int minCut(string s) {
			int n = s.length();
			
			vector<int> dp(n+1, 0);
			
			// initialize the dp array (the max cuts need for a string of length i to be palindrome is i - 1)
			for(int i = 0; i <= n; ++i) {
				dp[i] = i - 1;
			}
			
			for(int k = 0; k < n; ++k) {
				int i = k;
				int j = k;
				// expand for odd length
				for(; i >= 0 && j < n && s[i] == s[j]; --i, ++j) {
					//since the substring between i and j is a palindrome, so we'll put a cut on the left side of the string
					dp[j+1] = min(dp[j+1], dp[i] + 1);
				}
				
				i = k - 1;
				j = k;
				//expand for even length
				for(; i >= 0 && j < n && s[i] == s[j]; --i, ++j) {
					dp[j+1] = min(dp[j+1], dp[i] + 1);
				}
			}
			return dp[n];	
		}
};


int main(){
	string s = "aabcbabacbababaaabbccca";
	
	Solution obj;
	cout << obj.minCut(s);
	
	return 1;
}
