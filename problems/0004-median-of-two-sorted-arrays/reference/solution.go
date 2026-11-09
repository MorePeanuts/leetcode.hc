package main

// Finds the k-th smallest value of the two arrays by discarding k/2 values
// at a time, O(log(m + n)), instead of the Python reference's partition of
// the shorter array.
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	total := len(nums1) + len(nums2)
	if total%2 == 1 {
		return float64(kth(nums1, nums2, total/2+1))
	}
	return float64(kth(nums1, nums2, total/2)+kth(nums1, nums2, total/2+1)) / 2
}

// kth returns the k-th smallest value (1-based) of a and b together.
func kth(a, b []int, k int) int {
	for {
		if len(a) == 0 {
			return b[k-1]
		}
		if len(b) == 0 {
			return a[k-1]
		}
		if k == 1 {
			return min(a[0], b[0])
		}
		// Compare the (k/2)-th values (or the last, if shorter): the
		// smaller one and those before it are all below the k-th.
		i := min(len(a), k/2)
		j := min(len(b), k/2)
		if a[i-1] <= b[j-1] {
			a, k = a[i:], k-i
		} else {
			b, k = b[j:], k-j
		}
	}
}
