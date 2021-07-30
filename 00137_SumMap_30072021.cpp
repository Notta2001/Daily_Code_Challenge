#include<iostream>
#include<string>
#include <unordered_map>
using namespace std;

class MapSum {
	private:
		unordered_map<string,int> myMap;
	public:
		MapSum(){
		}
		
		void insert(string key, int val){
			myMap[key] = val;
		}
		
		int sum(string prefix){
			int res = 0;
			for(auto i:myMap){
	            if(i.first.substr(0,prefix.length())==prefix){
	                res+=i.second;
	            }
	        }
		}
};

int main(){
	MapSum obj;
	obj.insert("apple", 3);
	cout << obj.sum("ap");
	
}
//https://leetcode.com/problems/map-sum-pairs/
