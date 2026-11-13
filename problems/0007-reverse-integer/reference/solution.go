package main

func reverse(x int) int {
	// All arithmetic uses int32, including the negative form of INT_MIN.
	negative := x < 0
	remaining := int32(x)
	if !negative {
		remaining = -remaining
	}
	answer := int32(0)
	lastDigit := int32(-7)
	if negative {
		lastDigit = -8
	}
	for remaining != 0 {
		digit := remaining % 10
		if answer < -214748364 || (answer == -214748364 && digit < lastDigit) {
			return 0
		}
		answer = answer*10 + digit
		remaining /= 10
	}
	if !negative {
		answer = -answer
	}
	return int(answer)
}
