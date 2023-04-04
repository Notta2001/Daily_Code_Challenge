class Solution:
    def partitionString(self, s: str) -> int:
        if(len(s) == 1):
            return 1
        bitmask = 1 << (ord(s[0]) - 97)
        res = 1
        for i in range(1, len(s)):
            bit = 1 << (ord(s[i]) - 97)
            if (bitmask & bit):
                res = res + 1
                bitmask = bit
                continue
            else :
                bitmask = bitmask ^ bit

        return res
    
# https://leetcode.com/problems/optimal-partition-of-string