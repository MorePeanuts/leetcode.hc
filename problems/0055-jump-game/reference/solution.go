package main

func canJump(nums []int) bool {
	farthest := 0
	for index, jump := range nums {
		if index > farthest {
			return false
		}
		farthest = max(farthest, index+jump)
	}
	return true
}
