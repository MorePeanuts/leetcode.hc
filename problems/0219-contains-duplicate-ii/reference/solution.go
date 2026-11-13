package main

func containsNearbyDuplicate(nums []int, k int) bool {
	last := make(map[int]int)
	for i, v := range nums {
		if j, ok := last[v]; ok && i-j <= k {
			return true
		}
		last[v] = i
	}
	return false
}
