package main

type DetectSquares struct{ columns map[int]map[int]int }

func Constructor() DetectSquares { return DetectSquares{columns: map[int]map[int]int{}} }
func (this *DetectSquares) Add(point []int) {
	x, y := point[0], point[1]
	if this.columns[x] == nil {
		this.columns[x] = map[int]int{}
	}
	this.columns[x][y]++
}
func (this *DetectSquares) Count(point []int) int {
	x, y := point[0], point[1]
	total := 0
	for otherY, multiplicity := range this.columns[x] {
		side := otherY - y
		if side == 0 {
			continue
		}
		for _, otherX := range []int{x - side, x + side} {
			column := this.columns[otherX]
			total += multiplicity * column[y] * column[otherY]
		}
	}
	return total
}
