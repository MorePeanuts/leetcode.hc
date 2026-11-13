package main

func permute(nums []int) [][]int {
	answer := [][]int{}
	var search func(int)
	search = func(start int) {
		if start == len(nums) {
			answer = append(answer, append([]int{}, nums...))
			return
		}
		for i := len(nums) - 1; i >= start; i-- {
			nums[start], nums[i] = nums[i], nums[start]
			search(start + 1)
			nums[start], nums[i] = nums[i], nums[start]
		}
	}
	search(0)
	return answer
}
