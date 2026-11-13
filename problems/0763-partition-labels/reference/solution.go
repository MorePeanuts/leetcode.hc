package main

func partitionLabels(s string) []int {
	last := [26]int{}
	for i := range s {
		last[s[i]-'a'] = i
	}
	answer := []int{}
	start, end := 0, 0
	for i := range s {
		end = max(end, last[s[i]-'a'])
		if i == end {
			answer = append(answer, end-start+1)
			start = i + 1
		}
	}
	return answer
}
