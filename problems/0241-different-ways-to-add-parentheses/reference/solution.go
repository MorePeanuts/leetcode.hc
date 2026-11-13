package main

import "strconv"

func diffWaysToCompute(expression string) []int {
	memo := map[string][]int{}
	var solve func(string) []int
	solve = func(text string) []int {
		if answer, ok := memo[text]; ok {
			return answer
		}
		answer := []int{}
		for i := len(text) - 1; i >= 0; i-- {
			ch := text[i]
			if ch != '+' && ch != '-' && ch != '*' {
				continue
			}
			for _, left := range solve(text[:i]) {
				for _, right := range solve(text[i+1:]) {
					if ch == '+' {
						answer = append(answer, left+right)
					} else if ch == '-' {
						answer = append(answer, left-right)
					} else {
						answer = append(answer, left*right)
					}
				}
			}
		}
		if len(answer) == 0 {
			number, _ := strconv.Atoi(text)
			answer = append(answer, number)
		}
		memo[text] = answer
		return answer
	}
	return solve(expression)
}
