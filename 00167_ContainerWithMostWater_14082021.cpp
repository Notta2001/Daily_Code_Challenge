#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
    Start with the maximum width container and go to a shorter width
container if there is a vertical line longer than the current containers 
shorter line. This way we are compromising on the width but we are looking 
forward to a longer length container.
*/
class Solution {
    public:
        int maxArea(vector<int>& height) {
            int left = 0;
            int right = height.size() - 1;
            int ans = 0;
            while(left < right){
                int curWidth = right - left;
                int curHeight = min(height[left], height[right]);
                int curArea = curWidth*curHeight;
                ans = max(curArea, ans);
                if(height[right] > height[left])
                    left ++;
                else
                    right--;
            }

            return ans;
        }

        void printVect(vector<int>& v) {
            cout << "[";
            for(int i = 0; i < v.size(); ++i) 
                cout << " " << v[i] << " ";
            cout << "]" << endl;
        }
};

int main() {
    int arr[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    vector<int> height(arr, arr + sizeof(arr) / sizeof(int));

    Solution obj;
    obj.printVect(height);
    cout << obj.maxArea(height) << endl;

    return 1;
}
//https://leetcode.com/problems/container-with-most-water/