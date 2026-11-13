package main

import "strings"

func wordPattern(pattern string, s string) bool {
	words := strings.Fields(s)
	if len(words) != len(pattern) {
		return false
	}
	forward := map[byte]string{}
	reverse := map[string]byte{}
	for i, word := range words {
		c := pattern[i]
		if v, ok := forward[c]; ok && v != word {
			return false
		}
		if v, ok := reverse[word]; ok && v != c {
			return false
		}
		forward[c] = word
		reverse[word] = c
	}
	return true
}
