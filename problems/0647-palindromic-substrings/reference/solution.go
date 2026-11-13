package main

func countSubstrings(s string) int {
	count := 0
	for center := 0; center < 2*len(s)-1; center++ {
		left, right := center/2, (center+1)/2
		for left >= 0 && right < len(s) && s[left] == s[right] {
			count++
			left--
			right++
		}
	}
	return count
}
