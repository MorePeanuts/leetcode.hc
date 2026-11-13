package main

import "strings"

func removeKdigits(num string, k int) string {
	stack := make([]byte, 0, len(num))
	for i := 0; i < len(num); i++ {
		digit := num[i]
		for k > 0 && len(stack) > 0 && stack[len(stack)-1] > digit {
			stack = stack[:len(stack)-1]
			k--
		}
		stack = append(stack, digit)
	}
	if k > 0 {
		stack = stack[:len(stack)-k]
	}
	answer := strings.TrimLeft(string(stack), "0")
	if answer == "" {
		return "0"
	}
	return answer
}
