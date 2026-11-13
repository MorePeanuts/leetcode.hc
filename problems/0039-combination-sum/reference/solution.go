package main

import "sort"

func combinationSum(candidates []int, target int) [][]int {
	sort.Sort(sort.Reverse(sort.IntSlice(candidates)))
	answer := [][]int{}
	path := []int{}
	var search func(int, int)
	search = func(start, remaining int) {
		if remaining == 0 {
			answer = append(answer, append([]int{}, path...))
			return
		}
		for i := start; i < len(candidates); i++ {
			value := candidates[i]
			if value > remaining {
				continue
			}
			path = append(path, value)
			search(i, remaining-value)
			path = path[:len(path)-1]
		}
	}
	search(0, target)
	return answer
}
