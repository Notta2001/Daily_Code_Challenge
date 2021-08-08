#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
    public :
        string makeFancyString(string s) {
            int n = s.size();
            string ans = "";
            
            for(int i = 0; i < n; ++i){
                int j = i;
                while(j + 1 < n&& s[j+1] == s[i]) j++;
                int t = min(2, j-i+1);
                for(int k = 0; k <t; ++k) ans += s[i];
                i = j;
            }
            return ans;
        }
};

int main() {
    string s = "aaabbaaaa";
    
    Solution obj;
    cout << obj.makeFancyString(s) ;

    return 1;
}

//https://leetcode.com/problems/delete-characters-to-make-fancy-string/
