package main

func partition(s string) [][]string {
	n := len(s)
	palindrome := make([][]bool, n)
	for i := range palindrome {
		palindrome[i] = make([]bool, n)
	}
	for start := n - 1; start >= 0; start-- {
		for end := start; end < n; end++ {
			palindrome[start][end] = s[start] == s[end] && (end-start < 2 || palindrome[start+1][end-1])
		}
	}
	answer := [][]string{}
	path := []string{}
	var search func(int)
	search = func(start int) {
		if start == n {
			answer = append(answer, append([]string{}, path...))
			return
		}
		for end := n - 1; end >= start; end-- {
			if palindrome[start][end] {
				path = append(path, s[start:end+1])
				search(end + 1)
				path = path[:len(path)-1]
			}
		}
	}
	search(0)
	return answer
}
