class Solution:
    def minInseertions(self, s: str) -> int:
        n = len(s)
        dp = [0]*n
        # The number of step need to make i -> j become palindrome
        for i in range(n - 2, -1, -1):
            prev = 0
            for j in range(i + 1, n):
                # Before update: i+1 -> j, after: i -> j
                temp = dp[j]
                if s[i] == s[j]:
                    dp[j] = prev
                else:
                    # dp[j] now is i+1 -> j and dp[j-1] is i -> j-1: We can insert in the start or end of arr
                    dp[j] = min(dp[j], dp[j-1]) + 1
                prev = temp
        return dp[n-1]

# https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome
