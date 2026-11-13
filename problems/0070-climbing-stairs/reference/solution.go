package main

func climbStairs(n int) int {
	previous, current := 1, 1
	for i := 0; i < n; i++ {
		previous, current = current, previous+current
	}
	return previous
}
