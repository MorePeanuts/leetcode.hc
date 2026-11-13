class Solution:
    def canPartition(self, nums: list[int]) -> bool:
        total = sum(nums)
        if total % 2:
            return False
        target = total // 2
        possible = [False] * (target + 1)
        possible[0] = True
        for value in nums:
            for subtotal in range(target, value-1, -1):
                possible[subtotal] = possible[subtotal] or possible[subtotal-value]
        return possible[target]
