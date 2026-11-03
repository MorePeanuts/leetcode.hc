package main

func productExceptSelf(nums []int) []int {
	n := len(nums)
	prefix := make([]int, n+1)
	suffix := make([]int, n+1)
	prefix[0], suffix[n] = 1, 1
	for i := 0; i < n; i++ {
		prefix[i+1] = prefix[i] * nums[i]
	}
	for i := n - 1; i >= 0; i-- {
		suffix[i] = suffix[i+1] * nums[i]
	}
	answer := make([]int, n)
	for i := range nums {
		answer[i] = prefix[i] * suffix[i+1]
	}
	return answer
}
