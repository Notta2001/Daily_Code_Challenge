#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
    public:
        bool isPrefixString(string s, vector<string>& words) {
            string cur = "";
            for(int i = 0; i < words.size(); ++i){
                cur += words[i];
                if(s.compare(cur) == 0) return true;
            }
            return false;
    }
};

int main(){
    string arr[] = {"i", "love", "leetcode", "apples"};
    string s = "iloveleetcode";
    vector<string> words(arr, arr + sizeof(arr)/sizeof(string));

    Solution obj;
    cout << obj.isPrefixString(s, words);

    return 1;
}

//https://leetcode.com/problems/check-if-string-is-a-prefix-of-array/