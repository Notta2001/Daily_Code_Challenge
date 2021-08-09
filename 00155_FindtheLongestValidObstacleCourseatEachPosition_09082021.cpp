#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
For i, x in enumerate(nums):
    If x >= last element in the lis
        we append into the lis.
        ans[i] = len(lis)
    Else
        idx = Find the index of the smallest number > x
        lis[idx] = x; // Replace that number with x
        ans[i] = idx + 1
*/
class Solution {
    public:
        vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
            vector<int> lis;
            lis.push_back(obstacles[0]);
            obstacles[0] = 1;

            for(int i = 1; i < obstacles.size(); ++i) {
                if(lis[lis.size() - 1] <= obstacles[i]) { // Append to LIS if new element is >= last element in LIS
                    lis.push_back(obstacles[i]);
                    obstacles[i] = lis.size();                    
                }
                else {
                    int idx = upper_bound(lis.begin(), lis.end(), obstacles[i]) - lis.begin(); // find the index of the smallest number > x
                    lis[idx] = obstacles[i]; // Replace that number with x;
                    obstacles[i] = idx + 1;
                }            
            }

            return obstacles;
        }

        void printVector(vector<int> obstacles) {
            cout << "[" ;
            for(int i = 0; i < obstacles.size(); ++i) {
                cout << " " << obstacles[i] << " ";
            }
            cout << "]" << endl;
        }
};

int main () {
    int arr[] = {3, 1, 5, 6, 4, 2};
    vector<int> obstacles(arr, arr + sizeof(arr)/sizeof(int));

    Solution obj;
    obj.printVector(obstacles);
    vector<int> ans = obj.longestObstacleCourseAtEachPosition(obstacles);
    obj.printVector(ans);

    return 1;
}

//https://leetcode.com/contest/weekly-contest-253/problems/find-the-longest-valid-obstacle-course-at-each-position/