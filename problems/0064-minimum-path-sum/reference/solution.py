class Solution:
    def minPathSum(self, grid: list[list[int]]) -> int:
        dp = [float("inf")] * len(grid[0])
        dp[0] = 0
        for row in grid:
            for j, value in enumerate(row):
                dp[j] = min(dp[j], dp[j - 1] if j else float("inf")) + value
        return dp[-1]
