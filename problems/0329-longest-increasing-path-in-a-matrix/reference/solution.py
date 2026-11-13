from collections import deque

class Solution:
    def longestIncreasingPath(self, matrix: list[list[int]]) -> int:
        rows, cols = len(matrix), len(matrix[0])
        directions = ((1, 0), (-1, 0), (0, 1), (0, -1))
        outdegree = [[0] * cols for _ in range(rows)]
        queue = deque()
        for r in range(rows):
            for c in range(cols):
                outdegree[r][c] = sum(0 <= r+dr < rows and 0 <= c+dc < cols and matrix[r+dr][c+dc] > matrix[r][c] for dr, dc in directions)
                if outdegree[r][c] == 0:
                    queue.append((r, c))
        length = 0
        while queue:
            length += 1
            for _ in range(len(queue)):
                r, c = queue.popleft()
                for dr, dc in directions:
                    nr, nc = r+dr, c+dc
                    if 0 <= nr < rows and 0 <= nc < cols and matrix[nr][nc] < matrix[r][c]:
                        outdegree[nr][nc] -= 1
                        if outdegree[nr][nc] == 0:
                            queue.append((nr, nc))
        return length
