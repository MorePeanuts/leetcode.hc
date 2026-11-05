from collections import deque


class Solution:
    def numIslands(self, grid: list[list[str]]) -> int:
        # Breadth-first search from every unvisited land cell; no recursion,
        # so a snake-shaped island of 4.5 * 10^4 cells is fine.
        m, n = len(grid), len(grid[0])
        seen = [[False] * n for _ in range(m)]
        islands = 0
        for r in range(m):
            for c in range(n):
                if grid[r][c] != "1" or seen[r][c]:
                    continue
                islands += 1
                seen[r][c] = True
                queue = deque([(r, c)])
                while queue:
                    i, j = queue.popleft()
                    for x, y in ((i + 1, j), (i - 1, j), (i, j + 1), (i, j - 1)):
                        if 0 <= x < m and 0 <= y < n and grid[x][y] == "1" and not seen[x][y]:
                            seen[x][y] = True
                            queue.append((x, y))
        return islands
