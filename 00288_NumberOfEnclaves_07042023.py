class Solution:
    def dfs(self, i: int, j: int, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        if i < 0 or i >= m or j < 0 or j >= n or grid[i][j] != 1:
            return 0
        
        grid[i][j] = 0
        dx, dy = [1, -1, 0, 0], [0, 0, 1, -1]

        count = 1
        for k in range(4):
            nx, ny = i + dx[k], j + dy[k]
            count = count + self.dfs(nx, ny, grid)

        return count

    def numEnclaves(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])

        for i in range(m):
            for j in range(n):
                if (i == 0 or j == 0 or i == m-1 or j == n-1) and (grid[i][j] == 1):
                    self.dfs(i, j, grid)
        
        res = 0
        for i in range(1, m-1):
            for j in range(1, n-1):
                if grid[i][j] == 1:
                    res = res + self.dfs(i, j, grid)
        
        return res

# https://leetcode.com/problems/number-of-enclaves/