package main

import "sort"

func subsetsWithDup(nums []int) [][]int {
	sort.Sort(sort.Reverse(sort.IntSlice(nums)))
	answer := [][]int{}
	path := []int{}
	var search func(int)
	search = func(start int) {
		answer = append(answer, append([]int{}, path...))
		for i := start; i < len(nums); i++ {
			if i > start && nums[i] == nums[i-1] {
				continue
			}
			path = append(path, nums[i])
			search(i + 1)
			path = path[:len(path)-1]
		}
	}
	search(0)
	return answer
}
