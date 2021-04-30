#include<iostream>
#include<vector>

using namespace std;

// find Pivot index : the sum of all the numbers to the left of the index is equal to the sum of all the numbers to the right of the index

int findPivotIndex(vector<int> a){
	int n = a.size();
	if(n == 1) return 0;
	if(n == 0) return -1;
	int sumFromLeft[n];
	sumFromLeft[0] = a[0];
	for(int i = 1; i < n; ++i){
		sumFromLeft[i] = sumFromLeft[i-1] + a[i];
	}
	for(int i = 0; i < n-1; ++i){
		if(i == 0){
			int sumFromRight = sumFromLeft[n-1] - a[i];
			if(sumFromRight == 0) 
				return i;
		}
		else if(i == n-1){
			if(sumFromLeft[n-2] == 0)
				return i;
		}
		else {
			int sumFromRight = sumFromLeft[n-1] - sumFromLeft[i];
			if(sumFromRight == sumFromLeft[i-1])
				return i;
		}
		// khong duoc de sfl[i] == sfr[i] vi bi vi pham voi truong hop 1 phan tu
	}
	return -1;
}

int main(){
	int a[6] = {1,7,3,6,5,6};
	vector<int> b(&a[0], &a[0] + 6);
	for(int i = 0; i < b.size(); ++i){
		cout << b[i] ;
	}
	cout << endl;
	cout << findPivotIndex(b);
	return 1;
}
