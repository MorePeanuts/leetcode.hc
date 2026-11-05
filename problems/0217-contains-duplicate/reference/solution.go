package main

func containsDuplicate(nums []int) bool {
	seen := make(map[int]bool, len(nums))
	for _, x := range nums {
		if seen[x] {
			return true
		}
		seen[x] = true
	}
	return false
}
