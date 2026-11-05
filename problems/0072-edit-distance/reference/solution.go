package main

// dp[i][j] is the edit distance of word1[:i] and word2[:j]: O(m * n).
func minDistance(word1 string, word2 string) int {
	m, n := len(word1), len(word2)
	dp := make([][]int, m+1)
	for i := range dp {
		dp[i] = make([]int, n+1)
		dp[i][0] = i
	}
	for j := 0; j <= n; j++ {
		dp[0][j] = j
	}
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			if word1[i-1] == word2[j-1] {
				dp[i][j] = dp[i-1][j-1]
				continue
			}
			best := dp[i-1][j-1]
			if dp[i-1][j] < best {
				best = dp[i-1][j]
			}
			if dp[i][j-1] < best {
				best = dp[i][j-1]
			}
			dp[i][j] = best + 1
		}
	}
	return dp[m][n]
}
