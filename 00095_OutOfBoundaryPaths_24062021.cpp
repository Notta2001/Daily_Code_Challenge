#include<iostream>
#include<vector>;
using namespace std;

class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<int> > dp (m,vector<int>(n,0));
        vector<vector<int> >  temp=dp;
        int M=1e9+7;
        for(int k=0;k<N;k++){
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    long a=(i-1<0) ? 1: dp[i-1][j];
                    long b=(i+1>=m) ? 1: dp[i+1][j];
                    long c=(j-1<0) ? 1: dp[i][j-1];
                    long d=(j+1>=n) ? 1: dp[i][j+1];
                    
                    temp[i][j]=(a+b+c+d)%M;
                }
            }
            dp=temp;
        }
        return dp[i][j];
    }
};

int main(){
	Solution obj;
	cout << obj.findPaths(2, 2, 2, 0, 0);
	return 0;
}
