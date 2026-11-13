package main

func numDistinct(s string, t string) int {
	ways := make([]int, len(t)+1)
	ways[0] = 1
	for i := 0; i < len(s); i++ {
		for j := len(t); j > 0; j-- {
			if s[i] == t[j-1] {
				ways[j] += ways[j-1]
			}
		}
	}
	return ways[len(t)]
}
