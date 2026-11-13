package main

func majorityElement(nums []int) int {
	candidate, count := 0, 0
	for _, value := range nums {
		if count == 0 {
			candidate = value
		}
		if value == candidate {
			count++
		} else {
			count--
		}
	}
	return candidate
}
