package main

func checkSubarraySum(nums []int, k int) bool {
	first := map[int]int{0: -1}
	remainder := 0
	for i, v := range nums {
		remainder = (remainder + v) % k
		if j, ok := first[remainder]; ok {
			if i-j >= 2 {
				return true
			}
		} else {
			first[remainder] = i
		}
	}
	return false
}
