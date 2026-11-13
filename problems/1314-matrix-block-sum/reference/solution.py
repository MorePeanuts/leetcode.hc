class Solution:
    def matrixBlockSum(self, mat: list[list[int]], k: int) -> list[list[int]]:
        m, n = len(mat), len(mat[0])
        prefix = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(m):
            for j in range(n):
                prefix[i + 1][j + 1] = mat[i][j] + prefix[i][j + 1] + prefix[i + 1][j] - prefix[i][j]
        result = [[0] * n for _ in range(m)]
        for i in range(m):
            top, bottom = max(0, i - k), min(m, i + k + 1)
            for j in range(n):
                left, right = max(0, j - k), min(n, j + k + 1)
                result[i][j] = prefix[bottom][right] - prefix[top][right] - prefix[bottom][left] + prefix[top][left]
        return result
