#include<iostream>
#include<string>
#include<vector>
using namespace std;

#define mod 1000000007;

class Solution{
	public:
		int oneDigit (char a){
			if (a == '*') 
				return 9;
			return (a == '0') ? 0 : 1;
		}
		
		int twoDigits (char b, char a){
			// b: last character
			// a: current character
			if (b == '*'){
				if (a == '*')
					return 15;
				return (a >= '1' && a <= '6') ? 2 : 1;
			}
			else if (b == '1'){
				return (a == '*') ? 9 : 1;
			}
			else if (b == '2'){
				if (a == '*') 
					return 6;
				return (a >= '1' && a <= '6') ? 1 : 0;
			}
			
			return 0;
		}
		
		int numDecoding(string s){
			int n = s.size();
			vector<long long int> dp(n + 1, 0);
			dp[0] = 1;
			dp[1] = (s[0] == '*') ? 9 : 1;
			
			for (int i = 2; i < n+1; ++i){
				dp[i] += dp[i - 1] * oneDigit(s[i-1]);
				dp[i] += dp[i - 2] * twoDigits(s[i-2], s[i-1]);
			}
			
			return dp[n];
		}
};

int main () {
	string s = "1*2*345";
	Solution obj;
	cout << obj.numDecoding(s);
	return 1;
}

//// https://leetcode.com/problems/decode-ways-ii/
