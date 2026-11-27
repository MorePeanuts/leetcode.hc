package main

func updateMatrix(mat [][]int) [][]int {
	rows, cols := len(mat), len(mat[0])
	for r, row := range mat {
		for c, value := range row {
			if value == 0 {
				continue
			}
			best := rows + cols
			if r > 0 {
				best = min(best, mat[r-1][c]+1)
			}
			if c > 0 {
				best = min(best, row[c-1]+1)
			}
			row[c] = best
		}
	}
	for r := rows - 1; r >= 0; r-- {
		for c := cols - 1; c >= 0; c-- {
			if r+1 < rows {
				mat[r][c] = min(mat[r][c], mat[r+1][c]+1)
			}
			if c+1 < cols {
				mat[r][c] = min(mat[r][c], mat[r][c+1]+1)
			}
		}
	}
	return mat
}
