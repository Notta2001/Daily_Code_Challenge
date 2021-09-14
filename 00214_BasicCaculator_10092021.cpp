#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
    public: 
        int calculate(string str) {
            int result = 0, sign = 1;
            stack<int> s;
            for(int i = 0; i < str.length(); ++i) {
                if(str[i] == '+') 
                    sign = 1;
                else if(str[i] == '-')
                    sign = -1;
                else if(isdigit(str[i])) {
                    int n = str[i] - '0';
                    while(i+1 < str.length() && isdigit(str[i+1])) {
                        n = n*10 + (str[i+1] - '0');
                        ++i;
                    }
                    result += n*sign;
                }
                else if(str[i] == '(') {
                    s.push(result);
                    s.push(sign);
                    result = 0; 
                    sign = 1;
                }
                else if(str[i] == ')') {
                    int xSign = s.top();
                    s.pop();
                    int xResult = s.top();
                    s.pop();
                    result = (result*xSign) + xResult;
                }
            }
            return result;
        }
};

int main () {
    string s = "(1+(4+5+2)-3)+(6+8)";

    Solution obj;
    cout << s << " = ";
    cout << obj.calculate(s) ;
    
    return 1;
}

//https://leetcode.com/problems/basic-calculator/