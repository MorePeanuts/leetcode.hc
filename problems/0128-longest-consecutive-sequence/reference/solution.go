package main

func longestConsecutive(nums []int) int {
	values := make(map[int]bool, len(nums))
	for _, x := range nums {
		values[x] = true
	}
	best := 0
	for x := range values {
		if values[x-1] {
			continue
		}
		y := x
		for values[y+1] {
			y++
		}
		best = max(best, y-x+1)
	}
	return best
}
