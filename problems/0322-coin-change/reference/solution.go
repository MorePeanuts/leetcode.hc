package main

// Complete knapsack: dp[x] is the fewest coins summing to x, amounts in the
// outer loop; O(len(coins) * amount).
func coinChange(coins []int, amount int) int {
	inf := amount + 1
	dp := make([]int, amount+1)
	for x := 1; x <= amount; x++ {
		dp[x] = inf
		for _, c := range coins {
			if c <= x && dp[x-c]+1 < dp[x] {
				dp[x] = dp[x-c] + 1
			}
		}
	}
	if dp[amount] == inf {
		return -1
	}
	return dp[amount]
}
