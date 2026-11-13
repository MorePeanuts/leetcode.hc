package main

func spiralOrder(matrix [][]int) []int {
	top, bottom, left, right := 0, len(matrix)-1, 0, len(matrix[0])-1
	result := []int{}
	for top <= bottom && left <= right {
		for c := left; c <= right; c++ {
			result = append(result, matrix[top][c])
		}
		top++
		for r := top; r <= bottom; r++ {
			result = append(result, matrix[r][right])
		}
		right--
		if top <= bottom {
			for c := right; c >= left; c-- {
				result = append(result, matrix[bottom][c])
			}
			bottom--
		}
		if left <= right {
			for r := bottom; r >= top; r-- {
				result = append(result, matrix[r][left])
			}
			left++
		}
	}
	return result
}
