class Solution:
    def numWays(self, words: List[str], target: str) -> int:
        N = len(words)
        W = len(words[0])
        T = len(target)
        freq = [[0]*26 for i in range(W)]
        for i in range(W):
            for j in range(N):
                let = ord(words[j][i]) - ord('a')
                freq[i][let] += 1
        dp = [[0]*(W+1) for i in range(T+1)]
        for i in range(W+1):
          dp[0][i] = 1
        for i in range(T):
          tar = ord(target[i]) - ord('a')
          for j in range(W):
             num = freq[j][tar]
             dp[i+1][j+1] = (dp[i+1][j] + (dp[i][j]*num) % 1000000007) % 1000000007
        return int(dp[T][W])

# https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/