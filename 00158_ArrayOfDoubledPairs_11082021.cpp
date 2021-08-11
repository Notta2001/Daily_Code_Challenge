#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
    public:
        bool static cmp(int p, int q) {
            return abs(p) < abs(q);
        }
    
        bool canReorderDoubled(vector<int> & arr) {
            unordered_map<int, int> mp;
            
            for(int i = 0; i < arr.size(); ++i) {
                mp[arr[i]] ++;
            }

            sort(arr.begin(), arr.end(), cmp);
            
            for(int i = 0; i < arr.size(); ++i) {
                cout << arr[i] << " ";
            }
            cout << endl;

            for(int i = 0; i < arr.size(); ++i) {
                if(mp[arr[i]] == 0) 
                    continue;
                if(mp[2 * arr[i]] < 1) 
                    return false;
                mp[arr[i]] -- ;
                mp[2 * arr[i]] --;
            }

            return true;
        }
};

int main() {
    int arr[] = {-1, -2, -4, -2, 1, 2, 4, 16, 8, 8};
    vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));

    Solution obj;
    cout << obj.canReorderDoubled(nums);

    return 1;
}

//https://leetcode.com/problems/array-of-doubled-pairs/