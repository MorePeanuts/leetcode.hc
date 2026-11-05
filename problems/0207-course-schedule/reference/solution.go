package main

// Depth-first search with three colours: reaching a course that is still on
// the current path (grey) closes a cycle.
func canFinish(numCourses int, prerequisites [][]int) bool {
	needs := make([][]int, numCourses)
	for _, p := range prerequisites {
		needs[p[0]] = append(needs[p[0]], p[1])
	}
	const white, grey, black = 0, 1, 2
	colour := make([]int, numCourses)
	var acyclic func(int) bool
	acyclic = func(c int) bool {
		colour[c] = grey
		for _, p := range needs[c] {
			if colour[p] == grey || (colour[p] == white && !acyclic(p)) {
				return false
			}
		}
		colour[c] = black
		return true
	}
	for c := 0; c < numCourses; c++ {
		if colour[c] == white && !acyclic(c) {
			return false
		}
	}
	return true
}
