from collections import deque


class Solution:
    def nearestExit(self, maze: list[list[str]], entrance: list[int]) -> int:
        rows, cols = len(maze), len(maze[0])
        start_row, start_col = entrance
        seen = [[False] * cols for _ in range(rows)]
        seen[start_row][start_col] = True
        queue = deque([(start_row, start_col, 0)])
        while queue:
            row, col, distance = queue.popleft()
            if distance > 0 and (row == 0 or row == rows - 1 or col == 0 or col == cols - 1):
                return distance
            for dr, dc in ((1, 0), (-1, 0), (0, 1), (0, -1)):
                nr, nc = row + dr, col + dc
                if 0 <= nr < rows and 0 <= nc < cols and maze[nr][nc] == "." and not seen[nr][nc]:
                    seen[nr][nc] = True
                    queue.append((nr, nc, distance + 1))
        return -1
