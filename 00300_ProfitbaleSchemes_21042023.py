class Solution:
    def profitableSchemes(self, N: int, minProfit: int, group: List[int], profit: List[int]) -> int:
        G = len(group)
        dp = [[0] * (N + 1) for _ in range(minProfit + 1)]

        for n in range(N + 1):
            dp[0][n] = 1

        # Use each group of people
        for i in range(G):
            for p in reversed(range(minProfit + 1)):
                for n in reversed(range(N + 1)):
                    # The number of way to make p profit from n people
                    dp[p][n] += dp[max(0, p - profit[i])][n - group[i]] if group[i] <= n else 0
        return dp[minProfit][N] % (10 ** 9 + 7)

# https://leetcode.com/problems/profitable-schemes
