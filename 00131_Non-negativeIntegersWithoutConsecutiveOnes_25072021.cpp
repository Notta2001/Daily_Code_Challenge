#include<iostream>
#include<vector>
#include<string>
using namespace std;

// 1. First of all we'll find the number of binary strings of length log2(n) + 1 with given condition using dynamic programming
// 2. Now we'll remove the strings which are greater than the current number and still we have count
class Solution {
	public:
		int findIntegers(int n){
			string binary = "";
			
			while(n){
				if(n%2){
					binary += "1";
				}
				else{
					binary += "0";
				}
				
				n /= 2;
			}
			
			int sz = binary.size();
			
			vector<int> a(sz+1); // eligible strings endings with 0
			vector<int> b(sz+1); // eligible strings endings with 1
			
			a[0] = 0;
			
			a[1] = 1;
			b[1] = 1;
			
			// we can append '0' to both the string ending with '0' and '1' but can't do the same with the strings ending with '1'
	
			for(int i = 2; i <= sz; ++i){
				a[i] = a[i-1] + b[i-1];
				b[i] = a[i-1];
			}
			
			int ans = a[sz] + b[sz];
			
			for(int i = sz-2; i >= 0; --i){
				if(binary[i] == '1' && binary[i+1] == '1'){ // because every ...11.... are greater than .......
					break;
				}
				if(binary[i] == '0' && binary[i+1] == '0'){ // because every ...00..... are less than ....01.....
					ans -= b[i+1];
				}
			}
			
			return ans;
		}
};

int main(){
	Solution obj;
	cout << obj.findIntegers(1000) << endl;
	cout << obj.findIntegers(10000) << endl;
	return 1;
}

//https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/
