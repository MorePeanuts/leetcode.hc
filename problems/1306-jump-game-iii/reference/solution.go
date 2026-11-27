package main

func canReach(arr []int, start int) bool {
	seen := make([]bool, len(arr))
	seen[start] = true
	stack := []int{start}
	for len(stack) > 0 {
		i := stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		if arr[i] == 0 {
			return true
		}
		for _, j := range [2]int{i - arr[i], i + arr[i]} {
			if j >= 0 && j < len(arr) && !seen[j] {
				seen[j] = true
				stack = append(stack, j)
			}
		}
	}
	return false
}
