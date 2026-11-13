package main

func maxCoins(nums []int) int {
	n := len(nums) + 2
	values := make([]int, n)
	values[0] = 1
	values[n-1] = 1
	copy(values[1:], nums)
	dp := make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, n)
	}
	for left := n - 3; left >= 0; left-- {
		for right := left + 2; right < n; right++ {
			for last := left + 1; last < right; last++ {
				dp[left][right] = max(dp[left][right], dp[left][last]+dp[last][right]+values[left]*values[last]*values[right])
			}
		}
	}
	return dp[0][n-1]
}
