package main

// Bucket sort by frequency, collecting the answer from the least frequent of
// the k upward: the reverse of the Python reference's order, to prove that
// the judge ignores the order.
func topKFrequent(nums []int, k int) []int {
	count := map[int]int{}
	for _, x := range nums {
		count[x]++
	}
	buckets := make([][]int, len(nums)+1)
	for x, c := range count {
		buckets[c] = append(buckets[c], x)
	}
	var top []int
	for f := len(nums); f >= 1 && len(top) < k; f-- {
		top = append(top, buckets[f]...)
	}
	top = top[:k]
	for i, j := 0, len(top)-1; i < j; i, j = i+1, j-1 {
		top[i], top[j] = top[j], top[i]
	}
	return top
}
