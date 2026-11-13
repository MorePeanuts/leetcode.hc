package main

func longestValidParentheses(s string) int {
	dp := make([]int, len(s))
	best := 0
	for i := 1; i < len(s); i++ {
		if s[i] == ')' {
			opening := i - dp[i-1] - 1
			if opening >= 0 && s[opening] == '(' {
				dp[i] = dp[i-1] + 2
				if opening > 0 {
					dp[i] += dp[opening-1]
				}
				best = max(best, dp[i])
			}
		}
	}
	return best
}
