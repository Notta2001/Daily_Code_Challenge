#include<iostream>
#include<queue>
#include<vector>
using namespace std;

typedef long long int lli;

bool isPossible(vector<int> & target){
	int n = target.size();
	lli sum = 0;
	if(n == 1){
		if(target[0] == 1){
			return true;
		} 
		else{
			return false;
		}
	}
	for(int i = 0; i < n; ++i){
		sum += target[i];
	}
	priority_queue<int> pq(target.begin(), target.end());
	while(2*pq.top() > sum){
		int y = pq.top();
		pq.pop();
		int remain = sum - y;
		int x = y - remain;
		if(x <= 0) return false;
		if(x > remain){
			x = x%remain + remain;
		}
		pq.push(x);
		sum = remain + x;
	}
	return sum == target.size();
}

int main (){
	int arr1[3] = {9, 3, 5};
	int arr2[2] = {1, 1000000};
	int arr3[4] = {1, 1, 1, 2};
	int arr4[2] = {8, 5};
	
	vector<int> res1(&arr1[0], &arr1[0] + 3);
	vector<int> res2(&arr2[0], &arr2[0] + 2);
	vector<int> res3(&arr3[0], &arr3[0] + 4);
	vector<int> res4(&arr4[0], &arr4[0] + 2);
	
	cout << isPossible(res1) << endl;
	cout << isPossible(res2) << endl;
	cout << isPossible(res3) << endl;
	cout << isPossible(res4) << endl;
	
	return 0;
}

// https://leetcode.com/problems/construct-target-array-with-multiple-sums/