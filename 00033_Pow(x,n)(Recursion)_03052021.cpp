#include<iostream>
using namespace std;

double myPow(double x, int n){
	// Stop condition 
	if(n == 0){
		return 1;
	}
	int n_2 = 0;
	if(n < 0){
		// 10^-1 = 1/10
		n_2 = n%2 == 0 ? -(n/2) : (-n-1)/2 ;
		x = 1/x;
	}
	else{
		n_2 = n%2 == 0 ? n/2 : (n-1)/2;
	}
	
	double t = myPow(x, n_2);
	return n%2 == 0 ? (t*t) : (x*t*t);
}

int main(){
	cout << myPow(2, 2000) << endl;
	cout << myPow(2, -20);
	return 0;
}
