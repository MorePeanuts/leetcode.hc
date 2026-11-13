package main

import "strings"

func restoreIpAddresses(s string) []string {
	answer := []string{}
	parts := []string{}
	var visit func(int)
	visit = func(start int) {
		remaining := 4 - len(parts)
		if len(s)-start < remaining || len(s)-start > 3*remaining {
			return
		}
		if remaining == 0 {
			answer = append(answer, strings.Join(parts, "."))
			return
		}
		// Try long segments first, producing another legal outer order.
		for length := 3; length >= 1; length-- {
			if start+length > len(s) {
				continue
			}
			part := s[start : start+length]
			if length > 1 && part[0] == '0' {
				continue
			}
			value := 0
			for i := 0; i < len(part); i++ {
				value = value*10 + int(part[i]-'0')
			}
			if value > 255 {
				continue
			}
			parts = append(parts, part)
			visit(start + length)
			parts = parts[:len(parts)-1]
		}
	}
	visit(0)
	return answer
}
