#include<iostream>
#include<vector>
using namespace std;

vector<int> constructArray(int n, int k){
	vector<int> res;
	int i = 1, j = n;
    while(i <= j)
    {
        if(k > 1) res.push_back(k-- % 2 ? i++ : j--);
        else res.push_back(i++);
            
    }
	for(int i = 0; i < res.size(); ++i){
		cout << res[i] << " ";
	}
	return res;
}

int main(){
	int n, k;
	cin >> n >> k;
	constructArray(n,k);
	return 0;	
}

// https://leetcode.com/problems/beautiful-arrangement-ii/