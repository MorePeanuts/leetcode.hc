package main

// A monotonic queue of indices whose values decrease, kept in a slice with
// a moving head: the head is the maximum of the window.
func maxSlidingWindow(nums []int, k int) []int {
	q := make([]int, 0, len(nums))
	head := 0
	out := make([]int, 0, len(nums)-k+1)
	for i, x := range nums {
		for len(q) > head && nums[q[len(q)-1]] <= x {
			q = q[:len(q)-1]
		}
		q = append(q, i)
		if q[head] <= i-k {
			head++
		}
		if i >= k-1 {
			out = append(out, nums[q[head]])
		}
	}
	return out
}
