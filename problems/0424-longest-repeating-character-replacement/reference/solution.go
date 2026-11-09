package main

// A window that never shrinks, as in the Python reference: it grows only
// when the most frequent letter seen in a window reaches a new high.
func characterReplacement(s string, k int) int {
	var count [26]int
	most, left := 0, 0
	for right := 0; right < len(s); right++ {
		i := s[right] - 'A'
		count[i]++
		if count[i] > most {
			most = count[i]
		}
		if right-left+1-most > k {
			count[s[left]-'A']--
			left++
		}
	}
	return len(s) - left
}
