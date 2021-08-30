from typing import List
class Solution:
    def maxCount(self, m: int, n: int, ops: List[List[int]]) -> int:
        if len(ops) == 0:
            return m*n
        for i in ops:
            m,n = min(m,i[0]), min(n,i[1])
        return m*n

m = 3
n = 3
ops = [[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3]]
obj = Solution()
print(obj.maxCount(m, n, ops))

#https://leetcode.com/problems/range-addition-ii/