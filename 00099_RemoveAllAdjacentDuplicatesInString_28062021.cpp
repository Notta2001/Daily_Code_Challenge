#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        string str = "";
        for(int i=0; i<n; i++){
            if(!str.empty()){
                if(str.back()==s[i]){
                    str.pop_back();
                }
                else{
                    str.push_back(s[i]);
                }
            }
            else{
                str.push_back(s[i]);
            }
        }
        return str;
    }
};

int main(){
	Solution obj;
	string s = "azxxzysdsafdnfkdslfndsklflajadfsdrjwoadsklfndsklfndsklfndsklndshkgewkrnewlfndslkfnreslfndsaklaghdskldjsklfnewklrfnsfmdsgnwlrhjewlkrnewklfndsafdsnfkgrklrnerlendsfmdsnflewrjsdfdsamgnrldsmejwiorjqwrjewrioewj";
	cout << obj.removeDuplicates(s);
	return 0;
}

//https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
