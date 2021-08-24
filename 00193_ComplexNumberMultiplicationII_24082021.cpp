#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

class Solution {
    public:
        string complexNumberMultiply(string num1, string num2) {
            int a, b, c, d;
            sscanf(num1.c_str(), "%d+%di", &a, &b);
            sscanf(num2.c_str(), "%d+%di", &c, &d);
            return to_string(a * c - b * d) + '+' + to_string(a * d + b * c) + "i";
        }
};

int main () {
    string num1 = "12+-12i";
    string num2 = "15+-4i";

    Solution obj;
    cout << "(" << num1 << ")" << " * " <<  "(" << num2 << ")" << " = ";
    cout << obj.complexNumberMultiply(num1, num2) << endl;

    return 1;
}

//https://leetcode.com/problems/complex-number-multiplication/