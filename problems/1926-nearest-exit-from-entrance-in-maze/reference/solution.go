package main

func nearestExit(maze [][]byte, entrance []int) int {
	rows, cols := len(maze), len(maze[0])
	seen := make([][]bool, rows)
	for r := range seen {
		seen[r] = make([]bool, cols)
	}
	seen[entrance[0]][entrance[1]] = true
	queue := [][3]int{{entrance[0], entrance[1], 0}}
	dirs := [][2]int{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}
	for head := 0; head < len(queue); head++ {
		cur := queue[head]
		r, c, d := cur[0], cur[1], cur[2]
		if d > 0 && (r == 0 || r == rows-1 || c == 0 || c == cols-1) {
			return d
		}
		for _, step := range dirs {
			nr, nc := r+step[0], c+step[1]
			if nr >= 0 && nr < rows && nc >= 0 && nc < cols && maze[nr][nc] == '.' && !seen[nr][nc] {
				seen[nr][nc] = true
				queue = append(queue, [3]int{nr, nc, d + 1})
			}
		}
	}
	return -1
}
