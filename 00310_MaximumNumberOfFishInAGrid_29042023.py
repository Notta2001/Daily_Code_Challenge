class Solution:
    def findMaxFish(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        res = 0
        for i in range(0, m):
            for j in range(0, n):
                if grid[i][j] != 0:
                    cur = self.dfs(i, j, grid)
                    res = max(res, cur)
        return res
        
    def dfs(self, i: int, j: int, grid: List[List[int]]) -> None:
        m, n = len(grid), len(grid[0])
        if i < 0 or i >= m or j < 0 or j >= n or grid[i][j] == 0:
            return 0

        count = grid[i][j]
        grid[i][j] = 0
        dx, dy = [1, -1, 0, 0], [0, 0, 1, -1]
        
        for k in range(4):
            nx, ny = i + dx[k], j + dy[k]
            count += self.dfs(nx, ny, grid)   
        return count