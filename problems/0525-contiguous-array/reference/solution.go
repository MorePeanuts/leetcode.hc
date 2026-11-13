package main

func findMaxLength(nums []int) int {
	first := map[int]int{0: -1}
	balance, answer := 0, 0
	for i, v := range nums {
		if v == 1 {
			balance++
		} else {
			balance--
		}
		if j, ok := first[balance]; ok {
			if i-j > answer {
				answer = i - j
			}
		} else {
			first[balance] = i
		}
	}
	return answer
}
