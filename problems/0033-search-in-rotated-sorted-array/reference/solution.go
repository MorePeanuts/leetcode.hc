package main

import "sort"

// Finds the rotation point first, then binary searches the sorted half that
// can hold the target: two searches instead of the Python reference's one.
func search(nums []int, target int) int {
	n := len(nums)
	// The index of the smallest value: the first one below nums[n-1]'s run.
	pivot := sort.Search(n, func(i int) bool { return nums[i] <= nums[n-1] })
	lo, hi := pivot, n
	if target > nums[n-1] {
		lo, hi = 0, pivot
	}
	i := lo + sort.SearchInts(nums[lo:hi], target)
	if i < hi && nums[i] == target {
		return i
	}
	return -1
}
