class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        hold, sold, rest = -prices[0], 0, 0
        for price in prices[1:]:
            hold, sold, rest = max(hold, rest - price), hold + price, max(rest, sold)
        return max(sold, rest)
