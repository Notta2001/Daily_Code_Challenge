//balance the bits https://codeforces.com/contest/1503/problem/A
#include<iostream>
#include<string>
using namespace std; 

void solve(){
	int n;    // The number of char in the string
	cin >> n;
	string s;
	cin >> s;
	int count_ones = 0; // the number of ones in arrays
	for(int i = 0; i < s.length(); ++i) if(s[i] == '1') count_ones ++;
	if(s[0] != '1' || s[n-1] != '1' || count_ones&1 ){ //count_ones&1 = count_ones % 2 == 0
		cout << "NO" <<endl;
		return;
	}
	
	string x,y;
	 
	int ones = 0;
	bool zeros = true;
	for(int i = 0; i < n; ++i){
		if(s[i] == '1'){
			if(ones < count_ones/2){
				x += '(';
				y += '(';
				ones ++;
			}
			else{
				x += ')';
				y += ')';
			}
		}
		else{
			if(zeros){
				x += '(';
				y += ')';
				zeros = false;
			}
			else{
				x += ')';
				y += '(';
				zeros = true;
			}
		}
	}
	cout <<"YES"<< endl;
	cout << x << endl;
	cout << y << endl;
	return;
}

int main(){
	int T;
	cin >> T;
	while(T--){
		solve();
	}
}

