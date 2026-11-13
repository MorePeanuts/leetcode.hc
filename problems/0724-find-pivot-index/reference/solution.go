package main

func pivotIndex(nums []int) int {
	total, left := 0, 0
	for _, v := range nums {
		total += v
	}
	for i, v := range nums {
		if left == total-left-v {
			return i
		}
		left += v
	}
	return -1
}
