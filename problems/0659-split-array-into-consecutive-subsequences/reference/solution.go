package main

func isPossible(nums []int) bool {
	previousCount, singles, pairs := 0, 0, 0
	for start := 0; start < len(nums); {
		if start > 0 && nums[start] != nums[start-1]+1 {
			if singles+pairs > 0 {
				return false
			}
			previousCount = 0
		}
		end := start + 1
		for end < len(nums) && nums[end] == nums[start] {
			end++
		}
		count := end - start

		// Every short sequence must receive a copy before longer ones can extend.
		if count < singles+pairs {
			return false
		}
		pairs = singles
		singles = max(0, count-previousCount)
		previousCount = count
		start = end
	}
	return singles+pairs == 0
}
