class Solution:
    def lengthOfLIS(self, nums: list[int]) -> int:
        # dp[i] is the length of the longest strictly increasing subsequence
        # ending at nums[i]: O(n^2), which the constraints (n <= 2500) accept.
        n = len(nums)
        dp = [1] * n
        for i in range(1, n):
            x = nums[i]
            best = 1
            for j in range(i):
                if nums[j] < x and dp[j] >= best:
                    best = dp[j] + 1
            dp[i] = best
        return max(dp)
