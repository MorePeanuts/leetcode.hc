package main

func canMeasureWater(x int, y int, target int) bool {
	if target > x+y {
		return false
	}
	for y != 0 {
		x, y = y, x%y
	}
	return target%x == 0
}
