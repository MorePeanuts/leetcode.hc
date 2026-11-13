package main

import "strings"

func decodeString(s string) string {
	prefixes := []string{}
	counts := []int{}
	current, count := "", 0
	for _, ch := range s {
		if ch >= '0' && ch <= '9' {
			count = count*10 + int(ch-'0')
		} else if ch == '[' {
			prefixes = append(prefixes, current)
			counts = append(counts, count)
			current = ""
			count = 0
		} else if ch == ']' {
			last := len(counts) - 1
			current = prefixes[last] + strings.Repeat(current, counts[last])
			prefixes = prefixes[:last]
			counts = counts[:last]
		} else {
			current += string(ch)
		}
	}
	return current
}
