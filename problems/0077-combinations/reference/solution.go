package main

func combine(n, k int) [][]int {
	result := [][]int{}
	path := make([]int, 0, k)
	var visit func(int)
	visit = func(upper int) {
		needed := k - len(path)
		if needed == 0 {
			result = append(result, append([]int(nil), path...))
			return
		}
		for value := upper; value >= needed; value-- {
			path = append(path, value)
			visit(value - 1)
			path = path[:len(path)-1]
		}
	}
	visit(n)
	return result
}
