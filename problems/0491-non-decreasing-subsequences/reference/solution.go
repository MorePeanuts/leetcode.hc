package main

func findSubsequences(nums []int) [][]int {
	answer := [][]int{}
	path := []int{}
	var visit func(int)
	visit = func(start int) {
		if len(path) >= 2 {
			answer = append(answer, append([]int{}, path...))
		}
		used := map[int]bool{}
		for i := start; i < len(nums); i++ {
			v := nums[i]
			if used[v] || (len(path) > 0 && v < path[len(path)-1]) {
				continue
			}
			used[v] = true
			path = append(path, v)
			visit(i + 1)
			path = path[:len(path)-1]
		}
	}
	visit(0)
	// The outer answer order is deliberately opposite to the Python reference.
	for i, j := 0, len(answer)-1; i < j; i, j = i+1, j-1 {
		answer[i], answer[j] = answer[j], answer[i]
	}
	return answer
}
