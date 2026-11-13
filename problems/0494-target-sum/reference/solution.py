class Solution:
    def findTargetSumWays(self, nums: list[int], target: int) -> int:
        total = sum(nums)
        if abs(target) > total or (total + target) % 2:
            return 0
        goal = (total + target) // 2
        ways = [0] * (goal + 1)
        ways[0] = 1
        for value in nums:
            for subtotal in range(goal, value - 1, -1):
                ways[subtotal] += ways[subtotal - value]
        return ways[goal]
