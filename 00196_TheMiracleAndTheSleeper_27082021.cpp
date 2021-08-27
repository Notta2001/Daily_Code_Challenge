#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void solve() {
            long long a , b;
            cin >> a >> b;
            long long mid = (b+1)/2;
            if(mid >= a)    
                cout << (mid - 1) << endl;
            else
                cout << (b%a) << endl;
        }
};

int main () {
    Solution obj;
    int n;
    cin >> n;
    while(n -- )
        obj.solve();
    return 1;
}