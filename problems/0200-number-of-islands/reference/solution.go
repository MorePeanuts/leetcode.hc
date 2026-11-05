package main

// Union-find over the land cells with path halving and union by size; each
// land cell joins its right and lower neighbours.
func numIslands(grid [][]byte) int {
	m, n := len(grid), len(grid[0])
	parent := make([]int, m*n)
	size := make([]int, m*n)
	count := 0
	for i := range parent {
		parent[i] = i
		size[i] = 1
		if grid[i/n][i%n] == '1' {
			count++
		}
	}
	find := func(x int) int {
		for parent[x] != x {
			parent[x] = parent[parent[x]]
			x = parent[x]
		}
		return x
	}
	union := func(a, b int) {
		ra, rb := find(a), find(b)
		if ra == rb {
			return
		}
		if size[ra] < size[rb] {
			ra, rb = rb, ra
		}
		parent[rb] = ra
		size[ra] += size[rb]
		count--
	}
	for r := 0; r < m; r++ {
		for c := 0; c < n; c++ {
			if grid[r][c] != '1' {
				continue
			}
			if c+1 < n && grid[r][c+1] == '1' {
				union(r*n+c, r*n+c+1)
			}
			if r+1 < m && grid[r+1][c] == '1' {
				union(r*n+c, (r+1)*n+c)
			}
		}
	}
	return count
}
