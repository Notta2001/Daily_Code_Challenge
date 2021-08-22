#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
    public:
        int minTimeToType(string word) {
            int ans = word.length();
            word = 'a' + word;
            for(int i = 0; i < word.length() - 1; ++i){
                int x = word[i];
                int y = word[i + 1];
                if(x > y) swap(x, y);
                ans += min(y - x, 26 + x - y);
            }
            return ans;
        }
};

int main () {
    string s = "fdsgabsoifdjsf";

    Solution obj;
    cout << s << endl;
    cout << obj.minTimeToType(s) << endl;

    return 1;
}

//https://leetcode.com/problems/minimum-time-to-type-word-using-special-typewriter/