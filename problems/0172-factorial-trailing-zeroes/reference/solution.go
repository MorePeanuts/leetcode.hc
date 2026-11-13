package main

func trailingZeroes(n int) int {
	answer := 0
	for n > 0 {
		n /= 5
		answer += n
	}
	return answer
}
