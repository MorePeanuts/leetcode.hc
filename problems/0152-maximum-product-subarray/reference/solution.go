package main

func maxProduct(nums []int) int {
	smallest, largest, answer := nums[0], nums[0], nums[0]
	for _, value := range nums[1:] {
		smallest, largest = min(value, value*smallest, value*largest), max(value, value*smallest, value*largest)
		answer = max(answer, largest)
	}
	return answer
}
