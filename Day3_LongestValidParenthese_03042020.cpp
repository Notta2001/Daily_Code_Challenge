#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int longestValidParenthese (string s){
	int res = 0;
	stack<int> st;
	st.push(-1);
	for(int i = 0; i < s.length(); ++i){
		if(s[i] == '('){
			st.push(i);
		}
		else{
			st.pop();
			if(!st.empty()){
				res = max(res, i - st.top());
			}
			else{
				st.push(i);
			}
		}
	}
	return res;
}

int main(){
	cout << longestValidParenthese("()((s())");
	return 0;
}
