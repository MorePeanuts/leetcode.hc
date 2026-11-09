class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        lowest = prices[0]
        best = 0
        for p in prices:
            if p < lowest:
                lowest = p
            elif p - lowest > best:
                best = p - lowest
        return best
