#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
    public:
        char slowestKey(vector<int>& releaseTimes, string keysPressed) {
            char res = keysPressed[0];
            int max = releaseTimes[0];
            for(int i = 0; i < releaseTimes.size() - 1; ++i) {
                int tmp = releaseTimes[i + 1] - releaseTimes[i];
                if(tmp > max) {
                    max = tmp;
                    res = keysPressed[i + 1];
                }
                else if(tmp == max && keysPressed[i+1] > res) {
                    res = keysPressed[i + 1];
                }
            }
            return res;
        }

        void printVect(vector<int>& nums) {
            cout << "[";
            for(int num : nums) 
                cout << " " << num << " ";
            cout << "]" << endl;
        }
};

int main() {
    int arr[] = {12, 23, 36, 46, 62};
    vector<int> releaseTimes(arr, arr + sizeof(arr) / sizeof(int));

    Solution obj;
    obj.printVect(releaseTimes);
    cout << obj.slowestKey(releaseTimes, "spuda");

    return 1;
}
// https://leetcode.com/problems/slowest-key/