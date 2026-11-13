package main

func minOperations(nums []int, x int) int {
	target := -x
	for _, v := range nums {
		target += v
	}
	if target < 0 {
		return -1
	}
	left, total, longest := 0, 0, -1
	if target == 0 {
		longest = 0
	}
	for right, v := range nums {
		total += v
		for left <= right && total > target {
			total -= nums[left]
			left++
		}
		if total == target && right-left+1 > longest {
			longest = right - left + 1
		}
	}
	if longest < 0 {
		return -1
	}
	return len(nums) - longest
}
