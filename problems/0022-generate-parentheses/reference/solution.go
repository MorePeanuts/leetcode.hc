package main

func generateParenthesis(n int) []string {
	result := []string{}
	path := make([]byte, 0, 2*n)
	var search func(int, int)
	search = func(opened, closed int) {
		if closed == n {
			result = append(result, string(path))
			return
		}
		if closed < opened {
			path = append(path, ')')
			search(opened, closed+1)
			path = path[:len(path)-1]
		}
		if opened < n {
			path = append(path, '(')
			search(opened+1, closed)
			path = path[:len(path)-1]
		}
	}
	search(0, 0)
	return result
}
