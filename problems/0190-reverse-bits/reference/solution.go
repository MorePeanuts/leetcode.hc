package main

func reverseBits(n int) int {
	answer := 0
	for i := 0; i < 32; i++ {
		answer = (answer << 1) | (n & 1)
		n >>= 1
	}
	return answer
}
