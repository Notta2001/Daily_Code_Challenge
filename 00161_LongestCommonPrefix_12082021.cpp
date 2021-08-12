#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int inCommon(string s1, string s2) {
        int count = 0;
        for(int i = 0; i < s1.length() && i < s2.length(); ++i) {
            if(s1[i] == s2[i])
                count ++;
            else
                break;
        }
            
        return count;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
            if(strs.size() == 0) return "";
            if(strs.size() == 1) return strs[0];

            int res = strs[0].length();
            for(int i = 0; i < strs.size(); ++i) {
                res = min(res, inCommon(strs[0], strs[i]));
                if(res == 0)
                    return "";
            }

            return strs[0].substr(0, res);
        }
};

int main () {
    string arr[] = {"flower", "flow", "flight"};
    cout << "[";
    for(int i = 0; i < 3; ++i) {
        cout << " " << arr[i] << " ";
    };
    cout << "]" << endl; 

    vector<string> strs(arr, arr + sizeof(arr) / sizeof(string));

    Solution obj;
    cout << obj.longestCommonPrefix(strs) << endl;

    return 1;
}

//https://leetcode.com/problems/longest-common-prefix/