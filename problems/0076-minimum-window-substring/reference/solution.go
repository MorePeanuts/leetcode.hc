package main

// The sliding window of the Python reference: need[c] is how many more c
// the window needs, missing how many of t's characters it still lacks.
func minWindow(s string, t string) string {
	var need [128]int
	for i := 0; i < len(t); i++ {
		need[t[i]]++
	}
	missing := len(t)
	left, bestStart, bestLen := 0, 0, len(s)+1
	for right := 0; right < len(s); right++ {
		c := s[right]
		if need[c] > 0 {
			missing--
		}
		need[c]--
		if missing == 0 {
			for need[s[left]] < 0 {
				need[s[left]]++
				left++
			}
			if right-left+1 < bestLen {
				bestStart, bestLen = left, right-left+1
			}
			need[s[left]]++
			missing++
			left++
		}
	}
	if bestLen > len(s) {
		return ""
	}
	return s[bestStart : bestStart+bestLen]
}
