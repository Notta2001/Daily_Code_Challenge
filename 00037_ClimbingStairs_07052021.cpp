#include<iostream>
#include<vector>
using namespace std;

long long int climbStairs(int n){
	if(n == 1) return 1;
	if(n == 2) return 2;
	vector<long long int> res(n+1, 0);
	res[1] = 1;
	res[2] = 2;
	for(int i = 3; i <= n; ++i){
		res[i] = res[i-1] + res[i-2];
	}
	return res[n];
}

int main(){
	cout << climbStairs(5) << endl;
	cout << climbStairs(100) << endl;
	cout << climbStairs(21) << endl;
	cout << climbStairs(87) << endl;
	return 1;
}


// https://leetcode.com/problems/climbing-stairs/