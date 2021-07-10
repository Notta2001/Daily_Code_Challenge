#include<iostream>
#include<string>
using namespace std;

// 'A' -> "1"
// 'B' -> "2"
// ...
// 'Z' -> "26"
// '*' can represent any digit from '1' to '9' 
// Given a string s containing digits and the '*' character, return the number of ways to decode it.

#define mod 1000000007
class Solution {
	public:
		int oneDigit(char a) {
			if(a == '*'){
				return 9;
			}
			else if(a >= '1')
				return 1;
			return 0;
		}
		
		int twoDigit(char b, char a){
			// a: current character
			// b: last character
			
			if (b == '*'){
				if (a == '*'){
					return 15;
				}
				else
					return (a >= '0' && a <= '6') ? 2: 1;
			}
			else if (b == '1'){
				return a == '*' ? 9: 1;
			}
			else if (b == '2'){
				if (a == '*')
					return 6;
				else 
					return (a >= '0' && a <= '6')? 1 : 0;
			}
			
			return 0;
		}
		
		int numDecodings(string s){
			long long int prev2, prev1, curr;
			if(s[0] == '0')
				return 0;
			
			int n = s.size();
			prev1 = s[0] == '*' ? 9 : 1;
			curr = prev1;
			prev2 = 1;
			
			for (int i = 1; i < n; ++i){
				curr = ((prev1*oneDigit(s[i])) + prev2*twoDigit(s[i-1], s[i])) % mod;
				prev2 = prev1;
				prev1 = curr;
			}
			return curr;
		}
};

int main(){
	string s = "1*2*345";
	Solution obj;
	cout << obj.numDecodings(s);
	return 1;
}

// https://leetcode.com/problems/decode-ways-ii/
