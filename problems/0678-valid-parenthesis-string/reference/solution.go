package main

func checkValidString(s string) bool {
	low, high := 0, 0
	for _, ch := range s {
		if ch == '(' {
			low++
			high++
		} else if ch == ')' {
			low--
			high--
		} else {
			low--
			high++
		}
		if high < 0 {
			return false
		}
		low = max(low, 0)
	}
	return low == 0
}
