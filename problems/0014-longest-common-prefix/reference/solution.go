package main

func longestCommonPrefix(strs []string) string {
	first := strs[0]
	for i := 0; i < len(first); i++ {
		for _, word := range strs[1:] {
			if i == len(word) || word[i] != first[i] {
				return first[:i]
			}
		}
	}
	return first
}
