package main

func setZeroes(matrix [][]int) {
	rows, cols := len(matrix), len(matrix[0])
	firstRow, firstCol := false, false
	for _, v := range matrix[0] {
		if v == 0 {
			firstRow = true
		}
	}
	for r := 0; r < rows; r++ {
		if matrix[r][0] == 0 {
			firstCol = true
		}
	}
	for r := 1; r < rows; r++ {
		for c := 1; c < cols; c++ {
			if matrix[r][c] == 0 {
				matrix[r][0] = 0
				matrix[0][c] = 0
			}
		}
	}
	for r := 1; r < rows; r++ {
		for c := 1; c < cols; c++ {
			if matrix[r][0] == 0 || matrix[0][c] == 0 {
				matrix[r][c] = 0
			}
		}
	}
	if firstRow {
		for c := 0; c < cols; c++ {
			matrix[0][c] = 0
		}
	}
	if firstCol {
		for r := 0; r < rows; r++ {
			matrix[r][0] = 0
		}
	}
}
