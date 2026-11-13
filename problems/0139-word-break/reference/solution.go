package main

func wordBreak(s string, wordDict []string) bool {
	words := map[string]bool{}
	longest := 0
	for _, word := range wordDict {
		words[word] = true
		longest = max(longest, len(word))
	}
	possible := make([]bool, len(s)+1)
	possible[0] = true
	for end := 1; end <= len(s); end++ {
		for start := max(0, end-longest); start < end; start++ {
			if possible[start] && words[s[start:end]] {
				possible[end] = true
				break
			}
		}
	}
	return possible[len(s)]
}
