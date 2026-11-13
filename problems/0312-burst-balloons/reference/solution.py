class Solution:
    def maxCoins(self, nums: list[int]) -> int:
        values = [1] + nums + [1]
        n = len(values)
        dp = [[0] * n for _ in range(n)]
        for left in range(n - 3, -1, -1):
            for right in range(left + 2, n):
                boundary = values[left] * values[right]
                best = 0
                for last in range(left + 1, right):
                    best = max(best, dp[left][last] + dp[last][right] + boundary * values[last])
                dp[left][right] = best
        return dp[0][-1]
