#include <iostream>
#include <queue>
#include <vector>

int constrainedSubsetSum(vector<int>& nums, int k) {
    int maxSum = nums[0];
    deque<int> maxSumQueue;

    for (int i = 0; i < nums.size(); i++) {
        nums[i] += !maxSumQueue.empty() ? maxSumQueue.front() : 0;
        maxSum = max(maxSum, nums[i]);

        while (!maxSumQueue.empty() && nums[i] > maxSumQueue.back()) {
            maxSumQueue.pop_back();
        }

        if (nums[i] > 0) {
            maxSumQueue.push_back(nums[i]);
        }

        if (i >= k && !maxSumQueue.empty() && maxSumQueue.front() == nums[i - k]) {
            maxSumQueue.pop_front();
        }
    }

    return maxSum;
}

int main() {
    vector<int> nums = {10, -2, 5, 2, 20};
    cout << constrainedSubsetSum(nums, 2); << endl;
    return 1;
}

// https://leetcode.com/problems/constrained-subsequence-sum/description/?envType=daily-question&envId=2023-10-21

// Update A[i] by adding the value at the front of the deque (if not empty). This step is essential as it helps to maintain the constraint j - i <= k.
// Update the res to be the maximum of the current res and A[i]. This is essentially updating the maximum subsequence sum.
// Check if the deque is not empty and the current element A[i] is greater than the last element in the deque. If so, remove the last element from the deque. This step ensures that the deque only contains elements in non-increasing order.
// If the current element A[i] is greater than 0, add it to the deque. This step is essential for maintaining a sequence of positive elements.
// Check if the index i is greater than or equal to k and if the deque is not empty and the front element in the deque is equal to A[i - k]. If all these conditions are met, it means that the front element in the deque is k steps behind the current element, so it is no longer valid for the subsequence. Remove it from the deque.