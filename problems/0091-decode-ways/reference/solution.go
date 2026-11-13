package main

func numDecodings(s string) int {
	twoBack, oneBack := 1, 0
	if s[0] != '0' {
		oneBack = 1
	}
	for i := 1; i < len(s); i++ {
		current := 0
		if s[i] != '0' {
			current = oneBack
		}
		if s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6') {
			current += twoBack
		}
		twoBack, oneBack = oneBack, current
	}
	return oneBack
}
