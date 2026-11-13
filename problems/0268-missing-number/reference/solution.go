package main

func missingNumber(nums []int) int {
	missing := len(nums)
	for index, value := range nums {
		missing ^= index ^ value
	}
	return missing
}
