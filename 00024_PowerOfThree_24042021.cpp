#include<iostream>
using namespace std;

bool isPowerOfThree(int n){
	if( n == 0)
        return false;
    if (n == 1)
        return true;
    return isPowerOfThree(n/3);
}

int main(){
	cout << isPowerOfThree(27) << endl;
	cout << isPowerOfThree(54) << endl;
	return 0;
}

// https://leetcode.com/problems/power-of-three/