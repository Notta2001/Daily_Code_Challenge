#include<iostream>
#include<string>
using namespace std;

class Solution {
    public:
        void solve() {
            int n;
            string s;
            cin >> n >> s;
            long long cnt0 = 0;
            long long cnt1 = 0;
            for(int i = 1; i <= n; ++i) 
                if(s[i] == '1')
                    cnt1 ++;
            if(cnt1 == n) {
                cout << "1 " << n - 1 << " 2 " << n << endl;
                return; 
            }
            int p = 0;
            for(int i = 1; i <= n; ++i) {
                if(s[i] == '0') {
                    p = i;
                    break;
                }
            }
            if(p - 1 < (n/2))
                cout << p << " " << n << " " << p + 1 << " " << n << endl;
            else 
                cout << 1 << " " << p << " " << 1 << " " << p - 1 << endl;
        }
};

int main () {
    Solution obj;
    int n;
    cin >> n;
    while(n--)
        obj.solve();
    return 1;
}
//https://codeforces.com/contest/1562/problem/C