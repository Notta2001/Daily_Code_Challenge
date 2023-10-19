#include<iostream>
using namespace std;

bool backspaceCompare(string s, string t) {
        int backSpace = 0;
        string a, b;
        for(int i = s.size() - 1; i >= 0; --i) {
            if(s[i] == '#') {
                backSpace += 1;
            } else {
                if(backSpace == 0) {
                    a += s[i];
                } else {
                    backSpace -= 1;
                }
            }
        }
        backSpace = 0;
        for(int i = t.size() - 1; i >= 0; --i) {
            if(t[i] == '#') {
                backSpace += 1;
            } else {
                if(backSpace == 0) {
                    b += t[i];
                } else {
                    backSpace -= 1;
                }
            }
        }
        return a == b;
    }

int main(){
	string s, t;
	res = backspaceCompare(s, t);
	cout << res << endl;
	return 0;
}

// https://leetcode.com/problems/backspace-string-compare/description/?envType=daily-question&envId=2023-10-19

