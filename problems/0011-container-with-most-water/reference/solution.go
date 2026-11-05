package main

// Two pointers like the Python reference, but after measuring a container it
// skips every line no taller than the side it gives up, since none of them
// can make a larger one.
func maxArea(height []int) int {
	lo, hi := 0, len(height)-1
	best := 0
	for lo < hi {
		h := height[lo]
		if height[hi] < h {
			h = height[hi]
		}
		if a := h * (hi - lo); a > best {
			best = a
		}
		for lo < hi && height[lo] <= h {
			lo++
		}
		for lo < hi && height[hi] <= h {
			hi--
		}
	}
	return best
}
