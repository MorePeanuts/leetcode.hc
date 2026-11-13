package main

func searchMatrix(matrix [][]int, target int) bool {
	r, c := 0, len(matrix[0])-1
	for r < len(matrix) && c >= 0 {
		if matrix[r][c] == target {
			return true
		}
		if matrix[r][c] > target {
			c--
		} else {
			r++
		}
	}
	return false
}
