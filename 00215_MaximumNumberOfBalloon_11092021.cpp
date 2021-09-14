#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int freq[26] = {0}; 
        for (char ch : text) ++freq[ch - 'a']; 
        return min({freq[0], freq[1], freq[11]/2, freq[13], freq[14]/2}); 
    }
};

int main() {
    string text = "loonbalxballpoon";

    cout << text << endl;
    Solution obj;
    cout << obj.maxNumberOfBalloons(text);

    return 1;
}

//https://leetcode.com/problems/maximum-number-of-balloons/