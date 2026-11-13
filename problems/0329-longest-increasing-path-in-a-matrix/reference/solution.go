package main

func longestIncreasingPath(matrix [][]int) int {
	rows, cols := len(matrix), len(matrix[0])
	directions := [][2]int{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}
	degree := make([][]int, rows)
	queue := make([][2]int, 0, rows*cols)
	for r := 0; r < rows; r++ {
		degree[r] = make([]int, cols)
		for c := 0; c < cols; c++ {
			for _, d := range directions {
				nr, nc := r+d[0], c+d[1]
				if nr >= 0 && nr < rows && nc >= 0 && nc < cols && matrix[nr][nc] > matrix[r][c] {
					degree[r][c]++
				}
			}
			if degree[r][c] == 0 {
				queue = append(queue, [2]int{r, c})
			}
		}
	}
	length, head := 0, 0
	for head < len(queue) {
		end := len(queue)
		length++
		for head < end {
			r, c := queue[head][0], queue[head][1]
			head++
			for _, d := range directions {
				nr, nc := r+d[0], c+d[1]
				if nr >= 0 && nr < rows && nc >= 0 && nc < cols && matrix[nr][nc] < matrix[r][c] {
					degree[nr][nc]--
					if degree[nr][nc] == 0 {
						queue = append(queue, [2]int{nr, nc})
					}
				}
			}
		}
	}
	return length
}
