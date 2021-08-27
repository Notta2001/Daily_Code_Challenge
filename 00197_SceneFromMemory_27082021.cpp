#include<iostream>
#include<string>
using namespace std;

class Solution {
        public:
        bool prime[110];
        void solve() {
            int k;
            string s;
            cin >> k >> s;
            for(int i = 0; i < k; ++i) {
                if(s[i] == '1' || s[i] == '4' || s[i] == '6' || s[i] == '8' || s[i] == '9') {
                    cout << 1 << endl;
                    cout << s[i] << endl;
                    return;
                }
            }
            for(int i = 0; i < k; ++i) {
                for(int j = i + 1; j < k; ++j) {
                    if(!prime[(s[i] - '0') * 10 + (s[j] - '0')]) {
                        cout << 2 << endl;
                        cout << s[i] << s[j] << endl;
                        return;
                    }
                }
            }
                

            
        }

        void makePrime() {
            for(int i = 2; i < 100; ++i) {
                prime[i] = 1;
                for(int j = 2; j * j <= i; ++j) {
                    if(i % j == 0){
                        prime[i] = 0;
                        break;
                    }
                }
            }
        }
};

int main () {
    Solution obj;
    int n;
    cin >> n;
    obj.makePrime();
    while(n--)
        obj.solve();
    return 1;
}