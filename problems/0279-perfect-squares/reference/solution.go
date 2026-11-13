package main

func numSquares(n int) int {
	dp := make([]int, n+1)
	for total := 1; total <= n; total++ {
		dp[total] = total
		for s := 1; s*s <= total; s++ {
			dp[total] = min(dp[total], dp[total-s*s]+1)
		}
	}
	return dp[n]
}
