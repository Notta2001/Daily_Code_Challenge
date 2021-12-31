#include<iostream>
using namespace std;

bool equals(int arr[], int arr1[]){
	for(int i = 0; i < 9; ++i){
		if(arr[i] != arr1[i])
			return false;
	}
	return true;
}

bool reOrderedPowerOf2(int N){
	int arr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	while(N > 0){
		arr[N%10] ++;
		N=N/10;
	}
	for(int i = 0; i < 31; ++i){
		int num = 1 << i;
		int arr1[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
		while(num > 0){
			arr1[num%10] ++;
			num = num/10;
		}
		if(equals(arr, arr1))
			return true;
	}
	return false;
}

int main(){
	cout << reOrderedPowerOf2(10) << endl;
	cout << reOrderedPowerOf2(16) << endl;
	cout << reOrderedPowerOf2(812) << endl;
	cout << reOrderedPowerOf2(1052) << endl;
	cout << reOrderedPowerOf2(4102) << endl;
	return 0;
}

// https://leetcode.com/problems/reordered-power-of-2/