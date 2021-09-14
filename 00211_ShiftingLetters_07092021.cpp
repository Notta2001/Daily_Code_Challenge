#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
    public:
        string shiftingLetters(string s, vector<int>& shifts) {
            long shift = 0;
            for(int i = s.size() - 1; i >= 0; i--) {
                s[i] = ((s[i] - 'a') + (shift + shifts[i] % 26)) % 26 + 'a';
                shift += shifts[i];
            }
            return s;
        }
};

int main() {
    string s = "abcsfewrqw";
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> shifts(arr, arr + sizeof(arr) / sizeof(int));

    Solution obj;
    cout << s << endl;
    s = obj.shiftingLetters(s, shifts);
    cout << s << endl;

    return 1;
}

//https://leetcode.com/problems/shifting-letters/