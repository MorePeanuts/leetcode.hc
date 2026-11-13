package main

func countBits(n int) []int {
	counts := make([]int, n+1)
	for value := 1; value <= n; value++ {
		counts[value] = counts[value>>1] + (value & 1)
	}
	return counts
}
