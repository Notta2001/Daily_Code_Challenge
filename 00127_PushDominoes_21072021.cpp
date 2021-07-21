#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
	public :
		string pushDominoes(string dominoes) {
		
			int n=dominoes.size();
			vector<int> left(n);
			vector<int> right(n);
		
			int k=-1;
			for(int i=0;i<n;i++){
				if(dominoes[i]=='R')
					k=0;
				else if(dominoes[i]=='.' && k>=0)
					k++;
				else
					k=-1;
		
				right[i]=k;
			}
		
			 for(int i=n-1;i>=0;i--){
				if(dominoes[i]=='L')
					k=0;
				else if(dominoes[i]=='.' && k>=0)
					k++;
				else
					k=-1;
		
				left[i]=k;
			}
			string ans="";
		
			for(int i=0;i<n;i++){
			  if(left[i]==-1 && right[i]==-1)
				  ans.push_back('.');
			  else if(left[i]==-1)  
				  ans.push_back('R');
			  else if(right[i]==-1)  
				  ans.push_back('L');
			  else if(right[i]<left[i])
				  ans.push_back('R');
			  else if(right[i]>left[i])
				  ans.push_back('L');
			  else if(right[i]==left[i])
				  ans.push_back('.');  
			}
		
			return ans;
		}
};

/*
    Just keep a track of nearest left in left array and nearest right in right array
    The one which is smaller will have more influence on that point
    If both are equal it implies no change to that domino
*/

int main (){
	string s = ".L.R...LR..L..";
	cout << s << endl;
	Solution obj;
	string ans = obj.pushDominoes(s);
	cout << ans;
	return 1;
}

//https://leetcode.com/problems/push-dominoes/
