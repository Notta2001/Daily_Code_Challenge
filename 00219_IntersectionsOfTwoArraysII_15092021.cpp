#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
            unordered_map<int, int> freq;
            vector<int> res;
            for(int num : nums1) freq[num] ++;

            for(int num : nums2) {
                if(freq[num]) {
                    res.push_back(num);
                    freq[num] --;
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

int main () {
    int arr1[] = {4, 9, 5};
    int arr2[] = {9, 4, 9, 8 ,4};
    vector<int> nums1(arr1, arr1 + sizeof(arr1) / sizeof(int));
    vector<int> nums2(arr2, arr2 + sizeof(arr2) / sizeof(int));

    Solution obj;
    cout << "Array 1 : ";
    obj.printVect(nums1);
    cout << "Array 2 : ";
    obj.printVect(nums2);
    cout << "Intersections : ";
    vector<int> res = obj.intersect(nums1, nums2);
    obj.printVect(res);
    return 1;
}

//https://leetcode.com/problems/intersection-of-two-arrays-ii/