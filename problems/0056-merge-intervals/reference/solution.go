package main

import "sort"

// Sorts by end, descending, and extends the current interval leftwards
// while the next one ends inside it: O(n log n). Returns the intervals in
// descending order, where the Python reference returns ascending order.
func merge(intervals [][]int) [][]int {
	s := make([][]int, len(intervals))
	copy(s, intervals)
	sort.Slice(s, func(a, b int) bool { return s[a][1] > s[b][1] })
	var out [][]int
	for _, iv := range s {
		if n := len(out); n > 0 && iv[1] >= out[n-1][0] {
			if iv[0] < out[n-1][0] {
				out[n-1][0] = iv[0]
			}
		} else {
			out = append(out, []int{iv[0], iv[1]})
		}
	}
	return out
}
