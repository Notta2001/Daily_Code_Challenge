#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int countBinarySubstrings(string s) {
	int cur = 1, prev = 0, 	res = 0;
	for(int i = 1; i < s.size(); ++ i){
		if(s[i] == s[i+1]){
			cur ++;
		}
		else{
			res += min(cur, prev);
			prev = cur;
			cur = 1;
		}
	}
	return res + min(cur, prev);
}

int main(){
	cout << countBinarySubstrings("00110011") << endl;
	cout << countBinarySubstrings("10101") << endl;
	return 0;
}
