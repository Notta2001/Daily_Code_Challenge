#include<iostream>
#include<set>
#include<vector>
using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int> >& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();
        int max1=INT_MIN;
        for(int i=0;i<m;i++){
            vector<int> val(n);          //this val stores the sum of different rectangles in matrix
            for(int j=i;j<m;j++){              //initializing to i so that we can get different set of rectangles
                for(int k1=0;k1<n;k1++){
						val[k1]+=matrix[k1][j];        
                    // cout<<val[k]<<"\n";
                }
                set<int> st;     //set for storing and easily finding the sums of different sets of rectangle
                st.insert(0);
                int ans=0;
                for(int k1=0;k1<n;k1++){
                    ans+=val[k1];
                    set<int>::iterator it = st.lower_bound(ans-k);           //It gives lower bound of ans-k which we need to find so that we can get maximum answer
                    if(it!=st.end()){
                        max1=max(max1,ans-*it);          //finding maximum for every found sum in set
                    }
                    st.insert(ans);             //updating the set with newly found sums of rectangle
                }
            }
        }
        return max1;
    }
};

int main (){
	int a[2][3] = {{1,0,1},{0,-2,3}};
	vector<vector<int> > arr;
	for(int i = 0; i < 2; ++i){
		for(int j = 0; j < 3; ++j){
			arr[i].push_back(a[i][j]);
		}
	}
	Solution obj;
	cout << obj.maxSumSubmatrix(arr, 3);
}
