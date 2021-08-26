#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
    public:
        bool isValidSerialization(string preorder) {
            int nodes = 1, n = preorder.length();
            for(int i = 0; i < n; ++i) {
                if(preorder[i] == ',')
                    continue;
                --nodes;
                if(nodes < 0)
                    return false;
                if(preorder[i] != '#') {
                    while(i < n && isdigit(preorder[i]))
                        ++i;
                    --i;
                    nodes += 2;
                }
            }
            return nodes == 0;
        }
};

int main () {
    string s1 = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    string s2 = "9,#,#,1";

    Solution obj;
    cout << obj.isValidSerialization(s1) << endl;
    cout << obj.isValidSerialization(s2) << endl;

    return 1;
}

//https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/