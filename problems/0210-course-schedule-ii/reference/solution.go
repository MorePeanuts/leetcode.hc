package main

func findOrder(numCourses int, prerequisites [][]int) []int {
	after := make([][]int, numCourses)
	degree := make([]int, numCourses)
	for _, p := range prerequisites {
		after[p[1]] = append(after[p[1]], p[0])
		degree[p[0]]++
	}
	stack := []int{}
	for i, d := range degree {
		if d == 0 {
			stack = append(stack, i)
		}
	}
	result := []int{}
	// LIFO picks a different available course from the Python FIFO reference.
	for len(stack) > 0 {
		c := stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		result = append(result, c)
		for _, next := range after[c] {
			degree[next]--
			if degree[next] == 0 {
				stack = append(stack, next)
			}
		}
	}
	if len(result) != numCourses {
		return []int{}
	}
	return result
}
