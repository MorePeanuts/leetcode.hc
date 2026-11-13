package main

func generateMatrix(n int) [][]int {
	a := make([][]int, n)
	for i := range a {
		a[i] = make([]int, n)
	}
	lo, hi, v := 0, n-1, 1
	for lo <= hi {
		for j := lo; j <= hi; j++ {
			a[lo][j] = v
			v++
		}
		for i := lo + 1; i <= hi; i++ {
			a[i][hi] = v
			v++
		}
		if lo < hi {
			for j := hi - 1; j >= lo; j-- {
				a[hi][j] = v
				v++
			}
			for i := hi - 1; i > lo; i-- {
				a[i][lo] = v
				v++
			}
		}
		lo++
		hi--
	}
	return a
}
