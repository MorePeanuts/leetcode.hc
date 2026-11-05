package main

// Expand around each center, scanning from the right and keeping the first
// longest found: returns the rightmost longest palindrome, where the Python
// reference returns the leftmost. O(n^2).
func longestPalindrome(s string) string {
	n := len(s)
	bestLo, bestHi := n-1, n
	for center := 2*n - 2; center >= 0; center-- {
		lo := center / 2
		hi := lo + center%2
		for lo >= 0 && hi < n && s[lo] == s[hi] {
			lo--
			hi++
		}
		if hi-lo-1 > bestHi-bestLo {
			bestLo, bestHi = lo+1, hi
		}
	}
	return s[bestLo:bestHi]
}
