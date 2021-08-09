#include<iostream>
#include<string>
using namespace std;

class Solution {
    public:
        string addStrings(string num1, string num2) {
            if(num1.length() > num2.length()){ // Length of num1 if always smaller than that of num2
                string cur = num1;
                num1 = num2;
                num2 = cur;
            }

            int n1 = num1.length();
            int n2 = num2.length();
            string res = "";
            int surplus = 0, a, b, total;

            for(int i = n1; i < n2; ++i) 
                num1 = '0' + num1;
            
            for(int i = n2 - 1; i >= 0; --i) {
                a = num1[i] - '0';
                b = num2[i] - '0';
                total = a + b + surplus;
                res = char('0' + total%10) + res;
                surplus = total / 10;
            }

            if(surplus > 0) 
                res = char('0' + surplus) + res;

            return res; 
        }
};

int main() {
    string s1 = "590";
    string s2 = "2410";

    Solution obj;
    string res = obj.addStrings(s1, s2);

    cout << s1 << " + " << s2 << " = " << res;

    return 1;
}

// https://leetcode.com/problems/add-strings/