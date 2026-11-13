package main

func numSubarrayProductLessThanK(nums []int, k int) int {
	if k <= 1 {
		return 0
	}
	product, left, answer := 1, 0, 0
	for right, v := range nums {
		product *= v
		for product >= k {
			product /= nums[left]
			left++
		}
		answer += right - left + 1
	}
	return answer
}
