from collections import deque


class Solution:
    def shortestPathBinaryMatrix(self, grid: list[list[int]]) -> int:
        n = len(grid)
        if grid[0][0] or grid[n - 1][n - 1]:
            return -1
        seen = [[False] * n for _ in range(n)]
        seen[0][0] = True
        queue = deque([(0, 0, 1)])
        while queue:
            row, col, distance = queue.popleft()
            if row == n - 1 and col == n - 1:
                return distance
            for dr in (-1, 0, 1):
                for dc in (-1, 0, 1):
                    if dr == 0 and dc == 0:
                        continue
                    nr, nc = row + dr, col + dc
                    if 0 <= nr < n and 0 <= nc < n and grid[nr][nc] == 0 and not seen[nr][nc]:
                        seen[nr][nc] = True
                        queue.append((nr, nc, distance + 1))
        return -1
