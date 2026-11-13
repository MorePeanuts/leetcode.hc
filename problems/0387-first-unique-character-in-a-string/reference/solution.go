package main

func firstUniqChar(s string) int {
	var counts [26]int
	for i := range s {
		counts[s[i]-'a']++
	}
	for i := range s {
		if counts[s[i]-'a'] == 1 {
			return i
		}
	}
	return -1
}
