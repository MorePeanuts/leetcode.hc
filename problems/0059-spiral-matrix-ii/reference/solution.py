class Solution:
    def generateMatrix(self, n: int) -> list[list[int]]:
        matrix = [[0] * n for _ in range(n)]
        row = col = 0
        dr, dc = 0, 1
        for value in range(1, n * n + 1):
            matrix[row][col] = value
            nr, nc = row + dr, col + dc
            if not (0 <= nr < n and 0 <= nc < n) or matrix[nr][nc]:
                dr, dc = dc, -dr
            row, col = row + dr, col + dc
        return matrix
