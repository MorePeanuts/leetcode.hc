package main

// Scan from right to left to exercise unordered comparison.
func findAnagrams(s string, p string) []int {
	var need, window [26]int
	for i := range p {
		need[p[i]-'a']++
	}
	answer := []int{}
	for left := len(s) - 1; left >= 0; left-- {
		window[s[left]-'a']++
		if left+len(p) < len(s) {
			window[s[left+len(p)]-'a']--
		}
		if left+len(p) <= len(s) && window == need {
			answer = append(answer, left)
		}
	}
	return answer
}
