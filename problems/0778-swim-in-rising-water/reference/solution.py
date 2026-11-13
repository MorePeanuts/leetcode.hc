from heapq import heappop, heappush


class Solution:
    def swimInWater(self, grid: list[list[int]]) -> int:
        n = len(grid)
        best = [[n * n] * n for _ in range(n)]
        best[0][0] = grid[0][0]
        queue = [(grid[0][0], 0, 0)]
        while queue:
            time, row, col = heappop(queue)
            if time != best[row][col]:
                continue
            if row == n - 1 and col == n - 1:
                return time
            for nr, nc in ((row - 1, col), (row + 1, col), (row, col - 1), (row, col + 1)):
                if 0 <= nr < n and 0 <= nc < n:
                    candidate = max(time, grid[nr][nc])
                    if candidate < best[nr][nc]:
                        best[nr][nc] = candidate
                        heappush(queue, (candidate, nr, nc))
        return -1
