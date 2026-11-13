package main

func matrixBlockSum(mat [][]int, k int) [][]int {
	m, n := len(mat), len(mat[0])
	p := make([][]int, m+1)
	for i := range p {
		p[i] = make([]int, n+1)
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			p[i+1][j+1] = mat[i][j] + p[i][j+1] + p[i+1][j] - p[i][j]
		}
	}
	answer := make([][]int, m)
	for i := 0; i < m; i++ {
		answer[i] = make([]int, n)
		top, bottom := max(0, i-k), min(m, i+k+1)
		for j := 0; j < n; j++ {
			left, right := max(0, j-k), min(n, j+k+1)
			answer[i][j] = p[bottom][right] - p[top][right] - p[bottom][left] + p[top][left]
		}
	}
	return answer
}
