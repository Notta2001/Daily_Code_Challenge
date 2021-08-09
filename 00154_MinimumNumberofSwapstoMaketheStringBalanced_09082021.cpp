#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
    public:
        int minSwaps(string s) {
            cout << s << endl;
            vector<int> id;
            int index = 0;
            int balance = 0;
            int res = 0;

            for(int i = s.length() - 1; i >= 0; --i) 
                if(s[i] == '[') 
                    id.push_back(i);

            for(int i = 0; i < s.length(); ++i) {
                if(s[i] == '[') 
                    balance ++;
                else {
                    if(balance > 0) 
                        balance --;
                    else {
                        //char cur = s[i];
                        //s[i] = s[id[index]];
                        //s[id[index]] = cur;
                        swap(s[i], s[id[index]]);
                        index ++;
                        res ++;
                        balance ++;
                    }
                }
            }

            cout << s << endl;

            return res;
        }
};

int main () {
    string s = "]]][[[";

    Solution obj;
    cout << obj.minSwaps(s) << endl;

    return 1;
}