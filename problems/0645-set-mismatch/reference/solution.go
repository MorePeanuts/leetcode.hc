package main

func findErrorNums(nums []int) []int {
	seen := make([]bool, len(nums)+1)
	duplicate, total := 0, 0
	for _, value := range nums {
		total += value
		if seen[value] {
			duplicate = value
		}
		seen[value] = true
	}
	n := len(nums)
	return []int{duplicate, n*(n+1)/2 - total + duplicate}
}
