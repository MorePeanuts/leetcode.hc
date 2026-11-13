package main

func maxSubArray(nums []int) int {
	current, best := nums[0], nums[0]
	for _, value := range nums[1:] {
		current = max(value, current+value)
		best = max(best, current)
	}
	return best
}
