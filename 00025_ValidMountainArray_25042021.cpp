//valid mountain array
// xac dinh day ma chi tang xong r giam 0, 1, 2, 3, 4, 3, 2, 1, 0. khong co phan tu nao bang nhau

#include<iostream>
#include<vector>
using namespace std;

bool validMountainArray(const vector <int> &a){
	int n = a.size();
	bool bIsIncreasing = true;
	if(n < 3) return false;
	for(int i = 0; i < n-1; ++i){
		int j = i + 1;
		if(a[i] > a[j]){
			if(bIsIncreasing == false){
				
			}
			else{
				if(i == 0){ // ngay tu dau da giam
					return false;
				}
				bIsIncreasing = false;
			}
		}
		else if(a[i] < a[j]){
			if(bIsIncreasing == true){
				
			}
			else{  // day dang xet la day giam
				return false;
			}
		}
		else{
			return false;
		}
	}
	
	if(bIsIncreasing == false) return true;
	return false;
}

int main(){
	int a[9] = {1, 2, 3, 4, 5, 4, 3, 2, 1};
	vector<int> aa(&a[0], &a[0]+9);
	for(int i = 0; i < aa.size(); ++i){
		cout << aa[i];
	}
	cout << endl;
	cout << validMountainArray(aa)<<endl;
	
	int b[9] = {1, 2, 3, 4, 5, 5, 3, 2, 1};
	vector<int> bb(&b[0], &b[0]+9);
	for(int i = 0; i < bb.size(); ++i){
		cout << bb[i];
	}
	cout << endl;
	cout << validMountainArray(bb)<<endl;
	
	return 0;
	
}

// https://leetcode.com/problems/valid-mountain-array/