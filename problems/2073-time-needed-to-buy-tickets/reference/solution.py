class Solution:
    def timeRequiredToBuy(self, tickets: list[int], k: int) -> int:
        target = tickets[k]
        return sum(min(count, target if i <= k else target - 1)
                   for i, count in enumerate(tickets))
