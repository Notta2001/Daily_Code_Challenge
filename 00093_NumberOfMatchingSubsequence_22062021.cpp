#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution{
	public:
		bool isSubsequence(string s, string word){
			int len1 = s.length();
			int len2 = word.length();
			if(len2 > len1) return false;
			int index = 0;
			for(int i = 0; i < len1; ++i){
				if(s[i] == word[index]) index ++;
				if(index == len2) return true;
			}
			return false;
		}
		
		int numMatchingSubseq(string s, vector<string>& words) {
		    int num=0;
		    unordered_map<string, bool> A;
		    for(int i=0; i<words.size(); i++){
		        if(A.find(words[i])!=A.end()){
		            if(A[words[i]]==true)
		                num++;
		        }
		        else
		        {   
		            bool t = isSubsequence(s, words[i]);
		            A[words[i]]=t;
		            if(t)
		            num++;
		        }
		    }
		    return num;
		}
};

int main(){
	Soulution obj;
	string arr[] = {"ahjpjau","ja","ahbwzgqnuk","tnmlanowax"};
	vector<string> words(arr, arr + sizeof(arr)/ sizeof(string));
	string s = "dsahjpjauf";
	cout << obj.numMatchingSubseq(s, words) << endl;
	return 1;
	
}

