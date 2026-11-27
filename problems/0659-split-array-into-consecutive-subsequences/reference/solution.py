from collections import Counter


class Solution:
    def isPossible(self, nums: list[int]) -> bool:
        remaining = Counter(nums)
        tails = Counter()
        for value in nums:
            if not remaining[value]:
                continue
            remaining[value] -= 1
            if tails[value - 1]:
                tails[value - 1] -= 1
                tails[value] += 1
            elif remaining[value + 1] and remaining[value + 2]:
                remaining[value + 1] -= 1
                remaining[value + 2] -= 1
                tails[value + 2] += 1
            else:
                return False
        return True
