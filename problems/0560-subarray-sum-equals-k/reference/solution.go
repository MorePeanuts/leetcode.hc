package main

// Prefix sums: a subarray ending here sums to k when an earlier prefix
// equals the current prefix minus k. O(n).
func subarraySum(nums []int, k int) int {
	seen := map[int]int{0: 1}
	prefix, count := 0, 0
	for _, x := range nums {
		prefix += x
		count += seen[prefix-k]
		seen[prefix]++
	}
	return count
}
