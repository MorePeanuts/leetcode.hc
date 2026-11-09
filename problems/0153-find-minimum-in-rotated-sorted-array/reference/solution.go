package main

import "sort"

// The values at or below the last one form a suffix that starts at the
// minimum: binary search its first index against the fixed nums[n-1],
// instead of the Python reference's moving upper bound.
func findMin(nums []int) int {
	last := nums[len(nums)-1]
	return nums[sort.Search(len(nums), func(i int) bool { return nums[i] <= last })]
}
