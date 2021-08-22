#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Solution {
    public:
        int rectangleArea(vector<vector<int>> & rectangles) {
            vector<vector<int>> line;
            for (auto rectangle : rectangles) {
                int x1 = rectangle[0], y1 = rectangle[1], x2 = rectangle[2], y2 = rectangle[3];
                line.push_back({y1, x1, x2, 1});
                line.push_back({y2, x1, x2, 0});
            }

            sort(line.begin(), line.end());
            for(int i = 0; i < line.size(); ++i)
                cout << line[i][0] << " " << line[i][1] << " " << line[i][2] << " " << line[i][3] << endl;
            long ans = 0, val = 0;
            int yy = 0, prev = 0;
            multiset<vector<int>> segments;
            for(auto elem : line) {
                int y = elem[0], x1 = elem[1], x2 = elem[2], close = elem[3];
                ans += val*(y - yy) % 1000000007;
                yy = y;
                if(close) segments.insert({x1, x2});
                else segments.erase(segments.find({x1, x2}));
                val = prev = 0;
                for(auto seg : segments) {
                    x1 = seg[0];
                    x2 = seg[1];
                    val += max(0, x2 - max(x1, prev));
                    prev = max(prev, x2);
                }
                cout << ans << endl;
            }
            return ans;
        }
};

int main () {
    int arr0[] = {0, 0, 2, 2};
    int arr1[] = {1, 1, 2, 3};
    int arr2[] = {1, 1, 3, 1};
    vector<int> rect0(arr0, arr0 + sizeof(arr0) / sizeof(int)); 
    vector<int> rect1(arr1, arr1 + sizeof(arr1) / sizeof(int)); 
    vector<int> rect2(arr2, arr2 + sizeof(arr2) / sizeof(int)); 
    vector<vector<int>> rectangles;
    rectangles.push_back(rect0);
    rectangles.push_back(rect1);
    rectangles.push_back(rect2);

    Solution obj;
    cout << obj.rectangleArea(rectangles) << endl;

    return 1;
}


//https://leetcode.com/problems/rectangle-area-ii/