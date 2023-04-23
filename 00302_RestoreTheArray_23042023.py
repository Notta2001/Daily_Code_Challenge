class Solution:
    def numberOfArrays(self, s: str, k: int) -> int:
        n = len(s)
        dp = [0] * (n + 1)
        dp[-1] = 1
        
        for i in range(n - 1, -1, -1):
            if s[i] == '0':
                continue
            num = 0
            j = i
            while j < n and int(s[i:j+1]) <= k:
                # dp[j+1] : Number of array can form from [s[i:j+1], j+1 -> n]]
                num += dp[j+1]
                j += 1
            dp[i] = num % (10 ** 9 + 7)
        
        return dp[0]

# https://leetcode.com/problems/restore-the-array/description/