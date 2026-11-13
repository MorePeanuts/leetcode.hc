package main

func minPathSum(grid [][]int) int {
	dp := make([]int, len(grid[0]))
	for i, row := range grid {
		for j, v := range row {
			if i == 0 && j == 0 {
				dp[j] = v
			} else if i == 0 {
				dp[j] = dp[j-1] + v
			} else if j == 0 {
				dp[j] += v
			} else {
				dp[j] = min(dp[j], dp[j-1]) + v
			}
		}
	}
	return dp[len(dp)-1]
}
