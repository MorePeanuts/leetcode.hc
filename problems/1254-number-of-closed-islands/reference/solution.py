class Solution:
    def closedIsland(self, grid: list[list[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        answer = 0
        for row in range(rows):
            for col in range(cols):
                if grid[row][col] != 0:
                    continue
                stack = [(row, col)]
                grid[row][col] = 1
                closed = True
                while stack:
                    r, c = stack.pop()
                    if r == 0 or c == 0 or r == rows - 1 or c == cols - 1:
                        closed = False
                    for nr, nc in ((r - 1, c), (r + 1, c), (r, c - 1), (r, c + 1)):
                        if 0 <= nr < rows and 0 <= nc < cols and grid[nr][nc] == 0:
                            grid[nr][nc] = 1
                            stack.append((nr, nc))
                answer += closed
        return answer
