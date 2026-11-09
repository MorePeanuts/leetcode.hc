class Solution:
    def minSubArrayLen(self, target: int, nums: list[int]) -> int:
        n = len(nums)
        best = n + 1
        total = 0
        left = 0
        for right in range(n):
            total += nums[right]
            while total >= target:
                if right - left + 1 < best:
                    best = right - left + 1
                total -= nums[left]
                left += 1
        return best if best <= n else 0
