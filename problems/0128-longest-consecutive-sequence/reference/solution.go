package main

import "sort"

// Sorts instead of hashing: a different algorithm from the Python reference.
func longestConsecutive(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	s := append([]int(nil), nums...)
	sort.Ints(s)
	best, run := 1, 1
	for i := 1; i < len(s); i++ {
		switch s[i] - s[i-1] {
		case 0:
		case 1:
			run++
			if run > best {
				best = run
			}
		default:
			run = 1
		}
	}
	return best
}
