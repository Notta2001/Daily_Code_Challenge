#include<iostream>
#include<vector>
using namespace std;

int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
    int count = 0;
    int j = -1, k = -1;
    for(int i = 0; i < A.size(); ++i){
        if(A[i] > R)
            k = i;
        if(A[i] >= L)
            j = i;
        count += j - k;
        cout << count << " "  << j << " " << k << endl;
    }
    return count;
}

// Note: because subarray need to contain valid max so the elements A[i] behind the max will increase 
// count by exactly the number which equals k - j
 

int main(){
	int arr[] = {2, 1, 4, 1, 3, 1, 1};
	vector<int> nums (arr, arr + sizeof(arr) / sizeof(int));
	cout << numSubarrayBoundedMax(nums, 2, 3);
}
