#include<iostream>
#include<string>
using namespace std;

class Solution{
	public:
		string customSortString(string order, string str){
			int cnt[128] = {0};
			for(int i = 0; i < str.length(); ++i) 
				++cnt[str[i]];
			int j = 0;
			
			for(int i = 0; i < order.length(); ++i) {
				while(cnt[order[i]] > 0){
					str[j++] = order[i];
					--cnt[order[i]];
				}
			}
			
			for(char c ='a'; c <= 'z'; ++c){
				while(cnt[c] > 0){
					str[j++] = c;
					--cnt[c];
				}
			}
			
			return str;
		}
};

int main(){
	string order = "cba";
	string str = "abcd";
	cout << str << endl;
	Solution obj;
	cout << obj.customSortString(order, str);
	return 1;
}

//https://leetcode.com/problems/custom-sort-string/
