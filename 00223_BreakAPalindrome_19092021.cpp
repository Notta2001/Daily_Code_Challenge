#include<iostream>
#include<string>
using namespace std;

class Solution {
    public:
        string breakPalindrome(string palindrome) {
            int length = palindrome.size();
            if(length == 1)
                return "";
            for(int i = 0; i < length/2; ++i) {
                if(palindrome[i] != 'a') {
                    palindrome[i] = 'a';
                    return palindrome;
                }
            }
            palindrome[length - 1] = 'b';
            return palindrome;
        }
};

int main () {
    string s = "abccba";

    Solution obj;
    cout << "Before : " << s << endl;
    s = obj.breakPalindrome(s);
    cout << "After  : " << s << endl;

    return 1;
}
//https://leetcode.com/problems/break-a-palindrome/