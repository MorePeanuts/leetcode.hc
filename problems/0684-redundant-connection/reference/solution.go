package main

func findRedundantConnection(edges [][]int) []int {
	parent, size := make([]int, len(edges)+1), make([]int, len(edges)+1)
	for i := range parent {
		parent[i] = i
		size[i] = 1
	}
	find := func(x int) int {
		for parent[x] != x {
			parent[x] = parent[parent[x]]
			x = parent[x]
		}
		return x
	}
	for _, e := range edges {
		a, b := find(e[0]), find(e[1])
		if a == b {
			return e
		}
		if size[a] < size[b] {
			a, b = b, a
		}
		parent[b] = a
		size[a] += size[b]
	}
	return []int{}
}
