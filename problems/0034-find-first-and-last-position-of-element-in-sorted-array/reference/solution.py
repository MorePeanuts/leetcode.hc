class Solution:
    def searchRange(self, nums: list[int], target: int) -> list[int]:
        def bound(strict: bool) -> int:
            lo, hi = 0, len(nums)
            while lo < hi:
                mid = (lo + hi) // 2
                if nums[mid] < target or (strict and nums[mid] == target):
                    lo = mid + 1
                else:
                    hi = mid
            return lo
        first = bound(False)
        if first == len(nums) or nums[first] != target:
            return [-1, -1]
        return [first, bound(True) - 1]
