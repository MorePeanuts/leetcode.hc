package main

// Two pointers from both ends, skipping the characters that are not ASCII
// letters or digits, and comparing letters case-insensitively.
func isPalindrome(s string) bool {
	i, j := 0, len(s)-1
	for i < j {
		if !isAlnum(s[i]) {
			i++
			continue
		}
		if !isAlnum(s[j]) {
			j--
			continue
		}
		if lower(s[i]) != lower(s[j]) {
			return false
		}
		i++
		j--
	}
	return true
}

func isAlnum(c byte) bool {
	return c >= '0' && c <= '9' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'
}

func lower(c byte) byte {
	if c >= 'A' && c <= 'Z' {
		return c + 'a' - 'A'
	}
	return c
}
