# Double-ended queue
"""
    For convenience, let's call the cell has value 0 is zero-cell, the cell has value 1 is one-cell, the distance of the
nearest 0 is distance.
    Firstly, we can see that the distance of all zero-cells are 0
    Similar idea with Topology sort, we process zero-cells first, then we use bfs to expand their neighbors with the
shortest distance.
"""
from collections import deque


class Solution:
    def updateMatrix(self, mat: list[list[int]]) -> list[list[int]]:
        m, n = len(mat), len(mat[0])
        DIR = [0, 1, 0, -1, 0]

        dist = [[-1] * n for _ in range(m)]
        q = deque([])  # Double-ended queue
        for r in range(m):
            for c in range(n):
                if mat[r][c] == 0:
                    q.append((r, c))
                    dist[r][c] = 0

        while q:
            r, c = q.popleft()
            for i in range(4):
                nr, nc = r + DIR[i], c + DIR[i + 1]
                if nr < 0 or nr == m or nc < 0 or nc == n: continue  # Skip outbound coords
                if dist[nr][nc] == -1:
                    dist[nr][nc] = dist[r][c] + 1
                    q.append((nr, nc))
        return dist


mat = [[0, 1, 1, 1, 0], [1, 1, 0, 1, 1], [1, 1, 1, 1, 0]]
obj = Solution()
dist = obj.updateMatrix(mat)
print(dist)
