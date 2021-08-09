#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
    public:
        int minStoneSum(vector<int>& piles, int k) {
            priority_queue<int> pq;

            for(int i = 0; i < piles.size(); ++i) {
                pq.push(piles[i]);
            }

            for(int i = 0; i < k; ++i) {
                int tp = pq.top();
                pq.pop();

                pq.push(tp/2 + 1);
            }
            
            int ans = 0;
            while(!pq.empty()) {
                ans += pq.top();
                pq.pop();
            }

            return ans;
        }
};

int main () {
    int arr[] = {5, 4, 9};
    vector<int> piles(arr, arr + sizeof(arr)/sizeof(int));

    Solution obj;
    cout << obj.minStoneSum(piles, 2);

    return 1;
}