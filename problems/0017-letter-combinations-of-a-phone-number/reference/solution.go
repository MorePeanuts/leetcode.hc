package main

func letterCombinations(digits string) []string {
	letters := [10]string{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}
	result := []string{}
	path := make([]byte, len(digits))
	var search func(int)
	search = func(pos int) {
		if pos == len(digits) {
			result = append(result, string(path))
			return
		}
		group := letters[digits[pos]-'0']
		for i := len(group) - 1; i >= 0; i-- {
			path[pos] = group[i]
			search(pos + 1)
		}
	}
	search(0)
	return result
}
