package main

func findPeakElement(nums []int) int {
	lo, hi := 0, len(nums)-1
	for lo < hi {
		mid := lo + (hi-lo+1)/2
		if nums[mid-1] < nums[mid] {
			lo = mid
		} else {
			hi = mid - 1
		}
	}
	return lo
}
