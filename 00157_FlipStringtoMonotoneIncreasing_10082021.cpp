#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
    public:
        int minFlipsMonoIncr(string s) {
           if(s.length() == 1) return 0;
            int total_zero = 0;
            int back_zero = 0;
            int prev_one = 0;
            int res = INT_MAX;

            for(int i = 0; i < s.length(); ++i) 
                if(s[i] == '0') back_zero++;
            total_zero = back_zero;
            int total_one = s.length() - total_zero;

            for(int i = 0; i < s.length(); ++i) {
                if(s[i] == '0') {
                    back_zero--;
                }
                else {
                    prev_one++;
                }
                res = min(res, prev_one + back_zero);
            }

            res = min(res, total_zero);
            res = min(res, total_one);

            return res;
        }
};

int main() {
    string s = "00011000";

    Solution obj;
    cout << obj.minFlipsMonoIncr(s) << endl;

    return 1;
}

// https://leetcode.com/problems/flip-string-to-monotone-increasing/