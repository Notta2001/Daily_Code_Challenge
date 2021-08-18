#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
    public:
        int numDecoding(string s) {
            int n = s.length();
            int dp = 0; 
            int dp1 = 1;
            int dp2 = 0;
            for(int i = n-1; i >= 0; --i){
                if(s[i] != '0')
                    dp += dp1;
                if(i + 1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6'))
                    dp += dp2;
                dp2 = dp1;
                dp1 = dp;
                dp = 0;
            }

            return dp1;
        }
};

int main () {
    string s = "226";
    
    Solution obj;
    cout << s << endl;
    cout << obj.numDecoding(s) << endl;

    return 1;
}

//https://leetcode.com/problems/decode-ways/