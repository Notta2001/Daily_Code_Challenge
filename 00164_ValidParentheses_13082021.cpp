#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
    public:
        bool isValid(string s) {
            int len = s.length();        
            stack<char> ss;
            for(int i = 0; i < len; i++) {
                switch(s[i]) {
                    case ')':
                        if(!ss.empty() && ss.top() == '(')
                            ss.pop();
                        else
                            return false;
                        break;
                    case ']':
                        if(!ss.empty() && ss.top() == '[')
                            ss.pop();
                        else
                            return false;
                        break;
                    case '}':
                        if(!ss.empty() && ss.top() == '{')
                            ss.pop();
                        else
                            return false;
                        break;
                    default:
                        ss.push(s[i]);
                } 
            }
            if(ss.empty())
                return true;
            return false;
        }
};


int main() {
    string s = "{[]}";
    /*
        () : round bracket
        [] : square bracket
        {} : curly bracket
    */

    Solution obj;
    cout << s << endl;
    cout << obj.isValid(s) << endl;

    return 1;
}

//https://leetcode.com/problems/valid-parentheses/