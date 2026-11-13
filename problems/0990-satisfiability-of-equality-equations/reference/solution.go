package main

func equationsPossible(equations []string) bool {
	var parent [26]int
	var size [26]int
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
	for _, e := range equations {
		if e[1] == '=' {
			a, b := find(int(e[0]-'a')), find(int(e[3]-'a'))
			if a != b {
				if size[a] < size[b] {
					a, b = b, a
				}
				parent[b] = a
				size[a] += size[b]
			}
		}
	}
	for _, e := range equations {
		if e[1] == '!' && find(int(e[0]-'a')) == find(int(e[3]-'a')) {
			return false
		}
	}
	return true
}
