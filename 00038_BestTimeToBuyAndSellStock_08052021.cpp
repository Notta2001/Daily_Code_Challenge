#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxProfit(vector<int> &prices){
	int res = 0;
	int min_price = INT_MAX;
	
	for(int i = 0; i < prices.size(); ++i){
		min_price = min(min_price, prices[i]);
		res = max(res, prices[i] - min_price);
	}
	
	return res;
}

int main(){
	int stock1[6] = {7, 1, 5, 3 ,6 , 4};
	int stock2[4] = {3, 4, 2, 6};
	vector<int> init1(&stock1[0], &stock1[0]+6);
	vector<int> init2(&stock2[0], &stock2[0]+4);
	
	cout << maxProfit(init1) << endl;
	cout << maxProfit(init2) << endl;
	
	return 0;
}

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/