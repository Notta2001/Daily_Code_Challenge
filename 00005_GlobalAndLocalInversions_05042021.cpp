#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isIdealPermutation(vector<int> &A) {
    int ma = -1;
    for(int i = 0; i < A.size() - 2; ++i){
        ma = max(ma, A[i]);
        if(ma > A[i+2]) return false;
    }
    return true;
}

int main(){
	vector<int> A;
	A.push_back(1);
	A.push_back(0);
	A.push_back(2);
	A.push_back(4);
	A.push_back(3);
	cout << isIdealPermutation(A);
	return 0;
}

