#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
    public:
        vector<vector<string>> groupAnagrams (vector<string>& strs) {
            unordered_map<string, vector<string>>m;
            vector<vector<string>> res;
            string tmp_sorted;

            for (int i = 0; i < strs.size(); ++ i) {
                tmp_sorted = strs[i];
                sort(tmp_sorted.begin(), tmp_sorted.end());
                m[tmp_sorted].push_back(strs[i]);
            }

            for (auto iter : m) {
                res.push_back(iter.second);
            }

            return res;
        }

        void printVector(vector<vector<string>>& res) {
            cout << "[";
            for(int i = 0; i < res.size(); ++i) {
                cout << "[";
                for(int j = 0; j < res[i].size(); ++j){
                    cout << " " << res[i][j] << " ";
                }
                cout << "]";
            }
            cout << "]" << endl;
        }
};

int main () {
    string arr[] = {"eat", "tea", "tan", "ate", "nat", "bat", "thang"};
    vector<string> strs(arr, arr + sizeof(arr) / sizeof(string));

    Solution obj;
    vector<vector<string>> res = obj.groupAnagrams(strs);
    obj.printVector(res);
    
    return 1;
}

//https://leetcode.com/problems/group-anagrams/