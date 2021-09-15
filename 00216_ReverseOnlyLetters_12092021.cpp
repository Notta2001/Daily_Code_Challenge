#include<iostream>
#include<ctype.h>
using namespace std;

class Solution {
    public:
        string reverseOnlyLetters(string s){
            int i = 0, j = s.length() - 1;
            while(i < j) {
                if(!isalpha(s[i]))
                    ++i;
                else if(!isalpha(s[j]))
                    --j;
                else {
                    char tmp = s[i];
                    s[i] = s[j];
                    s[j] = tmp;
                    ++i;
                    --j;
                }
            }
            return s;
        }
};

int main () {
    string s = "Test1ng-Leet=code-Q!";

    Solution obj;
    cout << s << endl;
    s = obj.reverseOnlyLetters(s);
    cout << s;

    return 1;
}

// https://leetcode.com/problems/reverse-only-letters/