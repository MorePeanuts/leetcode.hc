package main

func pacificAtlantic(heights [][]int) [][]int {
	rows, cols := len(heights), len(heights[0])
	dirs := [][2]int{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}
	reach := func(starts [][2]int) [][]bool {
		seen := make([][]bool, rows)
		for r := range seen {
			seen[r] = make([]bool, cols)
		}
		queue := [][2]int{}
		for _, v := range starts {
			if !seen[v[0]][v[1]] {
				seen[v[0]][v[1]] = true
				queue = append(queue, v)
			}
		}
		for h := 0; h < len(queue); h++ {
			v := queue[h]
			for _, d := range dirs {
				r, c := v[0]+d[0], v[1]+d[1]
				if r >= 0 && r < rows && c >= 0 && c < cols && !seen[r][c] && heights[r][c] >= heights[v[0]][v[1]] {
					seen[r][c] = true
					queue = append(queue, [2]int{r, c})
				}
			}
		}
		return seen
	}
	p, a := [][2]int{}, [][2]int{}
	for r := 0; r < rows; r++ {
		p = append(p, [2]int{r, 0})
		a = append(a, [2]int{r, cols - 1})
	}
	for c := 0; c < cols; c++ {
		p = append(p, [2]int{0, c})
		a = append(a, [2]int{rows - 1, c})
	}
	x, y := reach(p), reach(a)
	out := [][]int{}
	// Reverse row-major order to exercise unordered comparison.
	for r := rows - 1; r >= 0; r-- {
		for c := cols - 1; c >= 0; c-- {
			if x[r][c] && y[r][c] {
				out = append(out, []int{r, c})
			}
		}
	}
	return out
}
