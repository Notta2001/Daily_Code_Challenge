#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
    public:
        int numDecodings(string s) {
            int n = s.length();
            vector<int> nums (n+1, 0);
            nums[n] = 1;
            for(int i = n -1; i >= 0; --i){
                if(s[i] != '0')
                    nums[i] += nums[i+1];
                if (i+1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6'))
                    nums[i] += nums[i+2];
            }
            return nums[0];
        }
};

int main () {
    string s = "226";

    Solution obj;
    cout << s << endl;
    cout << obj.numDecodings(s) << endl;

    return 1;
}
// https://leetcode.com/problems/decode-ways/