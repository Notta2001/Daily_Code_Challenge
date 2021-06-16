#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

void backtrack(vector<string>& ans, string str, int open, int close, int max){

    if(str.length() == max*2){
        ans.push_back(str);
        return;
    }

    if(open < max)
        backtrack(ans, str+"(", open+1, close, max);
    if(close < open)
        backtrack(ans, str+")", open, close+1, max);
}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    backtrack(ans, "", 0, 0, n);
    return ans;
}

void printVector(vector<string> ans){
	for(int i = 0; i < ans.size(); ++i){
		cout << ans[i] << endl;
	}
}

int main(){
	vector<string> ans = generateParenthesis(3);
	printVector(ans);
	return 0;
}
