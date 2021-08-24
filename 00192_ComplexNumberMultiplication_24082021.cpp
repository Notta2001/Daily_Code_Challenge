#include<iostream>
#include<vector>
#include<string>
using namespace std;


class Solution {
    public:
        vector<string> split(string num) {
            vector<string> res;
            int idx = 0;
            for(int i = 0; i < num.length(); ++i) 
                if(num[i] == '+') {
                    idx = i;
                    break;
                }
            string real = num.substr(0, idx);
            string imag = num.substr(idx+1, num.size() - idx - 2);
            res.push_back(real);
            res.push_back(imag);
            return res;
        }

        int stoi(string num) {
            int signal = 1;
            if(num[0] == '-') {
                signal = -1;
                num = num.substr(1);
            }
            int number = 0;
            for(int i = 0; i < num.size(); ++i) {
                number *= 10;
                number += (num[i] - '0');
            }
            return number*signal;
        }

        string itos(int num) {
            if(num == 0) 
                return "0";
            string res = "";
            int cur = abs(num);
                
            while(cur > 0) {
                res = char(cur%10 + '0') + res;
                cur /= 10;
            }
            if(num < 0)
                res = '-' + res;
            return res;
        }

        string complexNumberMultiply(string num1, string num2) {
            vector<string> comp1 = split(num1);
            vector<string> comp2 = split(num2);

            int real1 = stoi(comp1[0]);
            int imag1 = stoi(comp1[1]);
            int real2 = stoi(comp2[0]);
            int imag2 = stoi(comp2[1]);

            int real = real1*real2 - imag1*imag2;
            int imag = real1*imag2 + real2*imag1;

            return itos(real) + '+' + itos(imag) + "i";

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