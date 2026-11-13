class Solution:
    def maxSubArray(self, nums: list[int]) -> int:
        current = best = nums[0]
        for value in nums[1:]:
            current = max(value, current + value)
            best = max(best, current)
        return best
