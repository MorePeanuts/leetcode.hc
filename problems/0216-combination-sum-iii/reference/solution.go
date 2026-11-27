package main

func combinationSum3(k, n int) [][]int {
	result := [][]int{}
	path := make([]int, 0, k)
	var visit func(int, int)
	visit = func(upper, remaining int) {
		needed := k - len(path)
		if needed == 0 {
			if remaining == 0 {
				result = append(result, append([]int(nil), path...))
			}
			return
		}
		if remaining <= 0 {
			return
		}
		for value := upper; value >= needed; value-- {
			path = append(path, value)
			visit(value-1, remaining-value)
			path = path[:len(path)-1]
		}
	}
	visit(9, n)
	return result
}
