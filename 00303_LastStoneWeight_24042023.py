class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        stones=[-s for s in stones]
        heapify(stones)
        while len(stones)>1:
            # heappop return the smallest value of heap tree
            first=heappop(stones)*-1
            second=heappop(stones)*-1
            lastover=abs(first-second)
            heappush(stones,lastover*-1)

        return -stones[0]    
    
# https://leetcode.com/problems/last-stone-weight/