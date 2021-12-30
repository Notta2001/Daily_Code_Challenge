//Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
//A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

#include<iostream>
#include<vector>
#include<string>
using namespace std;

void letterCombinationRecursive(vector<string> &res, string digits, string current, int index, string mapping[]){
	if(index == digits.length()){
		res.push_back(current);
		return;
	}
	string letters = mapping[digits[index] - '0'];
	for(int i = 0; i < letters.length(); ++i){
		letterCombinationRecursive(res, digits, current + letters[i], index + 1, mapping);
	}
}
vector<string> letterCombinations(string digits){
	vector<string> res;
	if(digits.length() == 0){
		return res;
	}
	string mapping[] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	letterCombinationRecursive(res, digits, "", 0, mapping );
	return res;
}

void print(vector<string> res){
	for(int i = 0; i < res.size(); ++i){
		cout << res[i] << endl;
	}
	return;
}

int main(){
	vector<string> res;
	string a = "5686";
	res = letterCombinations(a);
	print(res);
	return 0;
}

