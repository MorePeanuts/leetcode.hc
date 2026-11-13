from math import isqrt

class Solution:
    def numSquares(self, n: int) -> int:
        squares = [i * i for i in range(1, isqrt(n) + 1)]
        dp = [0] + [n + 1] * n
        for total in range(1, n + 1):
            for square in squares:
                if square > total:
                    break
                dp[total] = min(dp[total], dp[total - square] + 1)
        return dp[n]
