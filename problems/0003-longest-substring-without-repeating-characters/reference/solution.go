package main

// A window whose start jumps past the previous occurrence of the character
// just read; the last index of each byte is kept in an array.
func lengthOfLongestSubstring(s string) int {
	var next [256]int // next[c] is one past the last index of c, 0 if unseen
	best, start := 0, 0
	for i := 0; i < len(s); i++ {
		if next[s[i]] > start {
			start = next[s[i]]
		}
		next[s[i]] = i + 1
		if i-start+1 > best {
			best = i - start + 1
		}
	}
	return best
}
