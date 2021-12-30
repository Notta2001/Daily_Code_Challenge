#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool halvesAreaAlike(string s){
	int res = 0;
	char a[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
	vector<char>symb (a, a + sizeof(a)/sizeof(char));
	for(int i = 0, k = s.size()/2; k <s.size(); ++i, ++k){
		if(find(symb.begin(), symb.end(), s[i]) != symb.end())
			res ++;
		if(find(symb.begin(), symb.end(),s[k]) != symb.end())
                res--;
    }
	return res == 0;
}

int main(){
	string s = "MerryChristmas";
	cout << halvesAreaAlike(s);
	s = "book";
	cout << halvesAreaAlike(s);
	return 0;
}

