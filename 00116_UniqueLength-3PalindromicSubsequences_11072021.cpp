#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>
using namespace std;

class Solution {
	public : 
		int countPalindromicSubsequence (string s) {
			vector<int> left (26);
			vector<int> right (26);
			unordered_set<string> h;
			
			// right
			for (int i = 0; i < s.size(); ++i) {
				right[s[i] - 'a'] ++;
			}
			
			for (int i = 0; i < s.size(); ++i) {
				right[s[i] - 'a'] --;
				for (int j = 0; j < 26; ++j){
					if (left[j] > 0 && right[j] > 0) {
						char x = 'a' + j;
						string palindrome = "";
						palindrome = palindrome + x + s[i] + x;
						
						if (h.count(palindrome) == true)
							continue;
							
						h.insert(palindrome);
						cout << palindrome << endl;
					}
				}
				left[s[i] - 'a'] ++;
			}
			return h.size();
		}
};

int main () {
	string s = "bacbabacbacba";
	Solution obj;
	obj.countPalindromicSubsequence(s);
	
	return 1;
}

//https://leetcode.com/problems/unique-length-3-palindromic-subsequences/
