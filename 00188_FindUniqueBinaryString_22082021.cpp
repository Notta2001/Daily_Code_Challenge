#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
    public:
        int stoi(string s) {
            int val = 0;
            for(int i = 0; i < s.length(); ++i) {
                val *= 2;
                val += s[i] - '0';
            }
            return val;
        }

        string itst(int val, int n) {
            string s = "";
            while(val > 0) {
                s = char(val%2 + '0') + s;
                val /= 2;
            }
            for(int i = s.length(); i < n; ++i) {
                s = '0' + s;
            }
            return s;
        }

        string findDifferentBinaryString(vector<string> &nums) {
            int n = nums.size();
            int val = 0;
            string s = itst(0, 1 << n);
            for(int i = 0; i < nums.size(); ++i)
                s[stoi(nums[i])] = '1';
            for(int i = 0; i < s.length(); ++i)
                if(s[i] == 0){
                    val = i;
                    break;
                }
                    
            return itst(val, n);
        }

        void printVect(vector<string>& nums) {
            for(int i = 0; i < nums.size(); ++i)
                cout << nums[i] << " ";
            cout << endl;
        }
};

int main () {
    string arr[] = {"111", "011", "001"};
    vector<string>nums(arr, arr + sizeof(arr) /  sizeof(string));

    Solution obj;
    obj.printVect(nums);
    cout << obj.findDifferentBinaryString(nums);

    return 1;
}