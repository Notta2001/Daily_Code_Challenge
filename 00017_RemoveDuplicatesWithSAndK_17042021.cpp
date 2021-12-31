#include<iostream>
using namespace std;

string removeDuplicates(string s, int k){
	int n = s.length();
	char st[n];
	int i = 0;
	for(int j = 0; j < n; ++j){
		char current_char = s[j];
		if(i >= k-1){
			int loop = k-1;
			while(loop > 0){
				if(st[i-loop] == current_char)
					loop --;
				else	
					break;
			}
			if(loop == 0) i -= (k-1);
			else{
				st[i] = current_char;
				++i;
			}
 		}
 		else{
 			st[i] = current_char;
 			i++;
		 }
	}
	string res = "";
	for(int j = 0; j < i; ++j){
		res += st[j];
	}
	return res;
}

string removeDuplicates1(string s, int k){
	int i,j=0,c=1;
    for(int i=1;i<s.size();i++){
        if(s[i]==s[j]){
            c++;
        }
        if(c==k){
            s.erase(j,k);
            c=1;
            i=0;j=0;
            cout<<s<<endl;
       	}		
        if(s[i]!=s[j]){
            j=i;
        } 
    }
    return s;
}

int main(){
	string s = "pbbcggttciiippooaais";
	int k = 2;
	cout << removeDuplicates(s, k);
	cout << removeDuplicates1(s,k);
	return 0;
}

// 