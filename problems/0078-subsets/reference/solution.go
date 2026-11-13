package main

func subsets(nums []int) [][]int {
	result := [][]int{}
	path := []int{}
	var visit func(int)
	visit = func(i int) {
		if i < 0 {
			result = append(result, append([]int{}, path...))
			return
		}
		path = append(path, nums[i])
		visit(i - 1)
		path = path[:len(path)-1]
		visit(i - 1)
	}
	visit(len(nums) - 1)
	return result
}
