from heapq import heappop, heappush


class Solution:
    def minimumEffortPath(self, heights: list[list[int]]) -> int:
        rows, cols = len(heights), len(heights[0])
        best = [[float("inf")] * cols for _ in range(rows)]
        best[0][0] = 0
        heap = [(0, 0, 0)]
        while heap:
            effort, row, col = heappop(heap)
            if effort != best[row][col]:
                continue
            if row == rows - 1 and col == cols - 1:
                return effort
            for dr, dc in ((1, 0), (-1, 0), (0, 1), (0, -1)):
                nr, nc = row + dr, col + dc
                if 0 <= nr < rows and 0 <= nc < cols:
                    candidate = max(effort, abs(heights[row][col] - heights[nr][nc]))
                    if candidate < best[nr][nc]:
                        best[nr][nc] = candidate
                        heappush(heap, (candidate, nr, nc))
        return 0
