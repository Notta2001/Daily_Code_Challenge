#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int minimumTotal(vector<vector<int> > &triangle){
	int n =  triangle.size();
	vector<int> dp(n+1, 0);
	for(int m = n-1; m >= 0; --m){
		for(int i = 0; i < triangle[m].size(); ++i){
			dp[i] = min(dp[i], dp[i+1]) + triangle[m][i];
		}
	}
	return dp[0];
}

int main(){
	vector<vector<int> > triangle;
	vector<int>a;
	a.push_back(2);
	vector<int>b;
	b.push_back(3);
	b.push_back(4);
	vector<int>c;
	c.push_back(6);
	c.push_back(5);
	c.push_back(7);
	vector<int>d;
	d.push_back(4);
	d.push_back(1);
	d.push_back(8);
	d.push_back(3);
	triangle.push_back(a);
	triangle.push_back(b);
	triangle.push_back(c);
	triangle.push_back(d);
	cout << minimumTotal(triangle);
	return 0;	
}

// https://leetcode.com/problems/triangle/