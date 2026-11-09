class Solution:
    def findMin(self, nums: list[int]) -> int:
        # The minimum is in nums[lo..hi]. A middle value above nums[hi] lies
        # before the drop, so the minimum is to its right; otherwise the
        # middle value is in the minimum's run, at or after it.
        lo, hi = 0, len(nums) - 1
        while lo < hi:
            mid = (lo + hi) // 2
            if nums[mid] > nums[hi]:
                lo = mid + 1
            else:
                hi = mid
        return nums[lo]
