#include<iostream>
#include<string>
using namespace std;

class Solution {
	public :
 		bool isIsomorphic (string s, string t) {
			if(s.length() == 1) return true;
			
			// we have to check from both side like if a map to b then b should be mapped to a
			// char not any other char 
			
			int stot[256] = {0}; // s corresponding to t
			int ttos[256] = {0}; // t corresponding to s
			
			int n = s.size();
			
			for (int i = 0; i < n; ++ i) {
				stot[s[i]] = t[i];
				ttos[t[i]] = s[i];
			} 
			
			for (int i = 0; i < n; ++ i) {
				if (stot[s[i]] == t[i] && ttos[t[i]] == s[i]) 
					continue;
				else 
					return false;
			}
			
			return true;
		}
};

int main () {
	string s = "paper";
	string t = "title";
	Solution obj;
	cout << obj.isIsomorphic(s, t);
	return 1;
}

//https://leetcode.com/problems/isomorphic-strings/
