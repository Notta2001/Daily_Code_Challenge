#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> dict(26,0);

bool bigger (const string &s1, const string &s2){
	const int length1 = s1.length();
	const int length2 = s2.length();
	for(int i = 0; i < min(length1, length2); ++i){
		if(dict[s1[i] - 'a'] < dict[s2[i] - 'a']) return false;
		if(dict[s1[i] - 'a'] > dict[s2[i] - 'a']) return true;
	}
	return length1 > length2;
}

bool isAlienSorted(vector<string> &words, string order){
	for(int i = 0; i < 26; ++i){
		dict[order[i] - 'a'] = i;
	}
	for(int i = 0; i < words.size()-1; ++i){
		if(bigger(words[i], words[i+1])){
			return false;
		}
	}
	return true;
}

int main(){
	vector<string> str;
	str.push_back("hello");
	str.push_back("letcode");
	string order = "hlabcdefgijkmnopqrstuvwxyz";
	cout << isAlienSorted(str, order);
	return 0;
}

