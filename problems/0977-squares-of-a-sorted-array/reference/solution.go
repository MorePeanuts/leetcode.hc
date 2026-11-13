package main

func sortedSquares(nums []int) []int {
	result := make([]int, len(nums))
	left, right := 0, len(nums)-1
	for i := len(nums) - 1; i >= 0; i-- {
		a, b := nums[left]*nums[left], nums[right]*nums[right]
		if a > b {
			result[i] = a
			left++
		} else {
			result[i] = b
			right--
		}
	}
	return result
}
