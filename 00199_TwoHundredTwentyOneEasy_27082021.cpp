#include<iostream>
#include<string>
using namespace std;

class Solution {
    public:
        void solve() {
            int a[300000], sum[300000];
            int n, q;
            string s;
            cin >> n >> q >> s;
            int id = 0;
            for(int i = 0; i < s.length(); ++i) {
                if(i&1) {
                    if(s[i] == '+') a[++id] = -1;
                    else a[++id] = 1;
                }
                else {
                    if(s[i] == '-') a[++id] = -1;
                    else a[++id] = 1;
                }
                sum[id] = sum[id - 1] + a[id];
                //cout << sum[id] << endl;
            }
            while (q--) {
                int l, r;
                cin >> l >> r;
                if(abs(sum[r] - sum[l-1]) == 0) cout << "0" << endl;
                else if(abs(sum[r] - sum[l-1]) & 1) cout << "1" << endl
                else cout << "2" << endl;
            }
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

//https://codeforces.com/contest/1562/problem/D1