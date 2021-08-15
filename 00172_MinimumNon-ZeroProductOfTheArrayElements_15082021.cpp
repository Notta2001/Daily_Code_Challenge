#include<iostream>
using namespace std;

class Solution {
    public:
        int MOD = 1000000007;

        int power(long n, long k, int m) {
            long ans = 1; 
            while (k) {
                if (k & 1) {
                    ans = (ans * n) % MOD; 
                    k--; 
                } else {
                    n = (n * n) % MOD; 
                    k /= 2; 
                }
            }
            return ans; 
        }

        int minNonZeroProduct(int p) {
            long x =  (1 << p) - 1; 
            return power((x-1) % MOD, (x-1)/2, MOD) * (x % MOD) % MOD; 
        }
};

int main () {
    Solution obj;
    for(int i = 1; i <= 30; ++i)
        cout << obj.minNonZeroProduct(i) << endl;

    return 1;
}

//https://leetcode.com/problems/minimum-non-zero-product-of-the-array-elements/