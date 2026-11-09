class Solution:
    def findMedianSortedArrays(self, nums1: list[int], nums2: list[int]) -> float:
        # Binary search how many of the shorter array's values go into the
        # lower half of the merged array, O(log min(m, n)). The lower half
        # holds (m + n + 1) // 2 values: i from nums1 and half - i from nums2,
        # and it is right when its largest value is at most the upper half's
        # smallest.
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
        m, n = len(nums1), len(nums2)
        half = (m + n + 1) // 2
        lo, hi = 0, m
        inf = float("inf")
        while True:
            i = (lo + hi) // 2
            j = half - i
            left1 = nums1[i - 1] if i > 0 else -inf
            right1 = nums1[i] if i < m else inf
            left2 = nums2[j - 1] if j > 0 else -inf
            right2 = nums2[j] if j < n else inf
            if left1 > right2:
                hi = i - 1
            elif left2 > right1:
                lo = i + 1
            else:
                left = max(left1, left2)
                if (m + n) % 2:
                    return float(left)
                return (left + min(right1, right2)) / 2
