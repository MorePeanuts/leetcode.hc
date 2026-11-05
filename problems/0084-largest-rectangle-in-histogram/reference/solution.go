package main

// Computes, for every bar, the nearest lower bar on each side in two passes,
// instead of the Python reference's single stack pass.
func largestRectangleArea(heights []int) int {
	n := len(heights)
	left := make([]int, n)  // index of the nearest lower bar to the left, or -1
	right := make([]int, n) // index of the nearest lower bar to the right, or n
	for i := 0; i < n; i++ {
		j := i - 1
		for j >= 0 && heights[j] >= heights[i] {
			j = left[j]
		}
		left[i] = j
	}
	for i := n - 1; i >= 0; i-- {
		j := i + 1
		for j < n && heights[j] >= heights[i] {
			j = right[j]
		}
		right[i] = j
	}
	best := 0
	for i, h := range heights {
		if a := h * (right[i] - left[i] - 1); a > best {
			best = a
		}
	}
	return best
}
