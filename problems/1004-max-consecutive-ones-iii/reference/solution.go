package main

func longestOnes(nums []int, k int) int {
	left, zeros, answer := 0, 0, 0
	for right, v := range nums {
		if v == 0 {
			zeros++
		}
		for zeros > k {
			if nums[left] == 0 {
				zeros--
			}
			left++
		}
		if right-left+1 > answer {
			answer = right - left + 1
		}
	}
	return answer
}
