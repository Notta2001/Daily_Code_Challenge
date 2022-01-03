#include<iostream>
#include<vector>
using namespace std;

vector<int> plusOne(vector<int> &a){
	int n = a.size();
	int soDu = 1;
	
	int i = n-1;
	while(i >= 0 && soDu > 0){
		int tmp = a[i] + soDu;
		a[i] = tmp%10;
		soDu = tmp/10;
		i--;
	}
	if(soDu == 0) return a;
	else{
		vector<int> b;
		b.push_back(soDu);
		for(int i = 0; i < n; ++i){
			b.push_back(a[i]);
		}
		return b;
	}
}

void print(vector<int> a){
	for(int i = 0; i < a.size(); ++i){
		cout << a[i];
	}
	cout << endl;
}

int main(){
	vector<int> a;
	a.push_back(9);
	a.push_back(9);
	a.push_back(9);
	print(a);
	vector<int> res = plusOne(a);
	print(res);
	return 1;
}

// https://leetcode.com/problems/plus-one/