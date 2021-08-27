#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
    public:
        bool isSubsequence(string a, string b) {
            int i = 0, j = 0;
            while(i < a.length() && j < b.length()) {
                if(a[i] == b[j])
                    ++i;
                ++j;
            }
            return i == a.length();
        }
        int findLUSlength(vector<string>& strs) {
            int n = strs.size(), best = -1;
            for(int i = 0; i < n; ++i) {
                bool valid = true;
                for(int j = 0; j < n; ++j) {
                    if(i!=j && isSubsequence(strs[i], strs[j])) {
                        valid = false;
                    }
                }
                if(valid)
                    best = max(best, int(strs[i].length()));
            }
            return best;
        }

        void printVect(vector<string>& strs) {
            cout << "[" ;
            for(int i = 0; i < strs.size(); ++ i )
                cout << " " << strs[i] << " ";
            cout << "]" << endl;
        }
};

int main () {
    vector<string> strs;
    strs.push_back("aba");
    strs.push_back("cdc");
    strs.push_back("eae");

    Solution obj;
    obj.printVect(strs);
    cout << obj.findLUSlength(strs) << endl;

    return 1;
}

//https://leetcode.com/problems/longest-uncommon-subsequence-ii/