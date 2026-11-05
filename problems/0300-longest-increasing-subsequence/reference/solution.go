package main

// dp[i] is the length of the longest strictly increasing subsequence ending
// at nums[i]: O(n^2), which the constraints (n <= 2500) accept.
func lengthOfLIS(nums []int) int {
	n := len(nums)
	dp := make([]int, n)
	ans := 0
	for i := 0; i < n; i++ {
		dp[i] = 1
		for j := 0; j < i; j++ {
			if nums[j] < nums[i] && dp[j]+1 > dp[i] {
				dp[i] = dp[j] + 1
			}
		}
		if dp[i] > ans {
			ans = dp[i]
		}
	}
	return ans
}
