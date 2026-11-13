package main

func rob(nums []int) int {
	if len(nums) == 1 {
		return nums[0]
	}
	linear := func(start, end int) int {
		twoBack, oneBack := 0, 0
		for i := start; i < end; i++ {
			twoBack, oneBack = oneBack, max(oneBack, twoBack+nums[i])
		}
		return oneBack
	}
	return max(linear(0, len(nums)-1), linear(1, len(nums)))
}
