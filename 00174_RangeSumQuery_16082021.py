from typing import List

class NumArray:
    def __init__(self, nums: List[int]) : 
        self.sums = nums
        for i in range(1, len(self.sums)):
            self.sums[i] += self.sums[i-1]

    def sumRange(self, left: int, right: int) :
        if left == 0:
            return self.sums[right]
        else :
            return self.sums[right] - self.sums[left-1]

arr = [-2, 0, 3, -5, 2, -1]
obj = NumArray(arr)
print(obj.sumRange(0, 2))
print(obj.sumRange(2, 5))
print(obj.sumRange(0, 5))

#https://leetcode.com/problems/range-sum-query-immutable/