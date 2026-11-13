class Solution:
    def longestValidParentheses(self, s: str) -> int:
        dp = [0] * len(s)
        best = 0
        for i in range(1, len(s)):
            if s[i] == ")":
                opening = i - dp[i - 1] - 1
                if opening >= 0 and s[opening] == "(":
                    dp[i] = dp[i - 1] + 2 + (dp[opening - 1] if opening else 0)
                    best = max(best, dp[i])
        return best
