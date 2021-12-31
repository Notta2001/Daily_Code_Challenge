#include<iostream>
#include<vector>
using namespace std;

vector<int> memoize(31, -1);

int fib(int n){
	if(memoize[n] != -1) return memoize[n];
	memoize[n] = fib(n-1) + fib(n-2);
	return memoize[n];
}

int main(){
	memoize[0] = 0;
 	memoize[1] = 1;
	cout << fib(27);
	return 0;
}

// https://leetcode.com/problems/fibonacci-number/