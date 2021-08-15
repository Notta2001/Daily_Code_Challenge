#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        string minWindow(string s, string t) {
            unordered_map<char, int> m;
            for(char c : t)
                m[c] ++;
            
            int counter = t.size();
            int start = 0;
            int end = 0;
            int len = INT_MAX;
            int begin = 0;

            while(end < s.size()) {
                m[s[end]]--;
                if(m[s[end]] >= 0)
                    counter --;
                end ++;
                while(counter == 0){
                    if(end - start < len){
                        len = end-start;
                        begin = start;
                    }
                    m[s[start]]++;
                    if(m[s[start]] > 0)
                        counter ++;
                    start++;
                }
            }
            if(len != INT_MAX)
                return s.substr(begin, len);
            else
                return "";
        }
};

int main() {
    string s1 = "ADOBECODEBANC";
    string s2 = "ABC";
    cout << "First string : " << s1 << endl;
    cout << "Second string : " << s2 << endl;

    Solution obj;
    cout << "Result : " << obj.minWindow(s1, s2) << endl;

    return 1;
}
//https://leetcode.com/problems/minimum-window-substring/