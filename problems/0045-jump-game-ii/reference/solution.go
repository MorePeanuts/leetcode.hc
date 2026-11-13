package main

func jump(nums []int) int {
	jumps, end, farthest := 0, 0, 0
	for index := 0; index < len(nums)-1; index++ {
		farthest = max(farthest, index+nums[index])
		if index == end {
			jumps++
			end = farthest
		}
	}
	return jumps
}
