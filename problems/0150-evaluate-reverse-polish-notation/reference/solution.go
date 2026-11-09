package main

import "strconv"

func evalRPN(tokens []string) int {
	stack := make([]int, 0, len(tokens))
	for _, t := range tokens {
		switch t {
		case "+", "-", "*", "/":
			b := stack[len(stack)-1]
			a := stack[len(stack)-2]
			stack = stack[:len(stack)-2]
			var r int
			switch t {
			case "+":
				r = a + b
			case "-":
				r = a - b
			case "*":
				r = a * b
			default:
				r = a / b // Go's division truncates toward zero
			}
			stack = append(stack, r)
		default:
			v, _ := strconv.Atoi(t)
			stack = append(stack, v)
		}
	}
	return stack[0]
}
