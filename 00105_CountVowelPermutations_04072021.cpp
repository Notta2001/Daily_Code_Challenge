#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countVowelPermutation(int n) {
        // a-->0
        // e-->1
        // i-->2
        // o-->3
        // u-->4
        // dp[i][j] means the no. of permutations till index i ending with vowel j
        // e can be at the last index if at previous index a or i is present   dp[i]['e']=dp[i-1]['a']+dp[i-1]['i']   where i is the index
        vector<vector<long> > dp(n,vector<long>(5,0));
        dp[0][0] = 1;
        dp[0][1] = 1;
        dp[0][2] = 1;
        dp[0][3] = 1;
        dp[0][4] = 1;
        for(int i=1;i<n;i++){
            dp[i][0]=(dp[i-1][1]+dp[i-1][2]+dp[i-1][4])%1000000007;
            dp[i][1]=(dp[i-1][0]+dp[i-1][2])%1000000007;
            dp[i][2]=(dp[i-1][1]+dp[i-1][3])%1000000007;
            dp[i][3]=(dp[i-1][2])%1000000007;
            dp[i][4]=(dp[i-1][2]+dp[i-1][3])%1000000007;
        }
        long ans=0;
        for(int i=0;i<5;i++) ans=(ans+dp[n-1][i])%1000000007;
        return ans;
    }
};

int main(){
	Solution obj;
	cout << obj.countVowelPermutation(2334);
	return 1;
}

// https://leetcode.com/problems/count-vowels-permutation/
