class Solution:
    def minOperations(self, nums: list[int], x: int) -> int:
        target = sum(nums) - x
        if target < 0:
            return -1
        left = total = 0
        longest = 0 if target == 0 else -1
        for right, value in enumerate(nums):
            total += value
            while left <= right and total > target:
                total -= nums[left]
                left += 1
            if total == target:
                longest = max(longest, right - left + 1)
        return len(nums) - longest if longest >= 0 else -1
