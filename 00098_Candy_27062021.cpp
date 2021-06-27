#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Take sample example:
// candies [] = [1, 1, 1, 1, 1, 1, 1] : Initialize candies with 1 candy each
// ratings [] = [1, 6, 10, 8, 7, 3, 2]
// After 1st iteration: update while going left to right: if ratings[i] > ratings[i-1] ---> candies[i]=candies[i-1]+1
// ratings [] = [1, 6, 10, 8, 7, 3, 2]
// candies [] = [1, 2, 3, 1, 1, 1, 1]
// After 2nd iteration : update candies while going right to left: if ratings[i] > ratings[i+1] ----> candies[i] = max(candies[i+1]+1, candies[i])
// ratings [] = [1, 6, 10, 8, 7, 3, 2]
// candies [] = [1, 2, 5, 4, 3, 2, 1]

class Solution{
public:
	int candy(vector<int> & ratings){
		cout << "Ratings: " << endl;
		printVector(ratings);
		int n = ratings.size();
		vector<int> candies (n, 1);
		
		// 1st iteration : update while going left to right
		for(int i = 1; i < n; ++i){
			if(ratings[i] > ratings[i-1]){
				candies[i] = candies[i-1]+1;
			}
		}
		cout << "After 1st iteration: " << endl;
		printVector(candies);
		
		int sum = candies[n-1];
		
		// 2nd iteration : update while going right to left
		for(int i = n-2; i >= 0; --i){
			if(ratings[i] > ratings[i+1]){
				candies[i] = max(candies[i], candies[i+1]+1);
			}
			sum = candies[i];
		}
		cout << "After 2nd iteration(answer): " << endl;
		printVector(candies);

		return sum;
	}
	
	void printVector(vector<int> &vec){
		cout << "[";
		for(int i = 0; i < vec.size(); ++i){
			cout << " " << vec[i] << " " ;
		}
		cout << "]" << endl;
	}
	
};

int main(){
	int arr [] = {1, 6, 10, 8, 7, 3, 2};
	vector<int> ratings(arr, arr + sizeof(arr)/ sizeof(int));
	Solution obj;
	cout << "Result: " << obj.candy(ratings);
	return 0;
}

//https://leetcode.com/problems/candy/
