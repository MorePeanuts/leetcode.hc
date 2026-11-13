package main

func getSum(a int, b int) int {
	x, y := int32(a), int32(b)
	for y != 0 {
		x, y = x^y, (x&y)<<1
	}
	return int(x)
}
