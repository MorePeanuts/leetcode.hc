package main

// Two pointers like the Python reference: the lower side is bounded by its
// own running maximum, since the other side is at least as tall.
func trap(height []int) int {
	lo, hi := 0, len(height)-1
	leftMax, rightMax, water := 0, 0, 0
	for lo < hi {
		if height[lo] < height[hi] {
			if height[lo] > leftMax {
				leftMax = height[lo]
			} else {
				water += leftMax - height[lo]
			}
			lo++
		} else {
			if height[hi] > rightMax {
				rightMax = height[hi]
			} else {
				water += rightMax - height[hi]
			}
			hi--
		}
	}
	return water
}
