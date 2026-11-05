class Solution:
    def coinChange(self, coins: list[int], amount: int) -> int:
        # Complete knapsack: dp[x] is the fewest coins summing to x, coins in
        # the outer loop; O(len(coins) * amount).
        inf = amount + 1
        dp = [0] + [inf] * amount
        for c in coins:
            for x in range(c, amount + 1):
                v = dp[x - c] + 1
                if v < dp[x]:
                    dp[x] = v
        return dp[amount] if dp[amount] != inf else -1
