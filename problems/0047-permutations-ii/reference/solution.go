package main

func permuteUnique(nums []int) [][]int {
	answer := [][]int{}
	var search func(int)
	search = func(start int) {
		if start == len(nums) {
			answer = append(answer, append([]int{}, nums...))
			return
		}
		var used [21]bool
		for i := len(nums) - 1; i >= start; i-- {
			key := nums[i] + 10
			if used[key] {
				continue
			}
			used[key] = true
			nums[start], nums[i] = nums[i], nums[start]
			search(start + 1)
			nums[start], nums[i] = nums[i], nums[start]
		}
	}
	search(0)
	return answer
}
