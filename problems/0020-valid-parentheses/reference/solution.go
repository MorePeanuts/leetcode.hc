package main

func isValid(s string) bool {
	stack := make([]byte, 0, len(s))
	for i := 0; i < len(s); i++ {
		c := s[i]
		var open byte
		switch c {
		case ')':
			open = '('
		case ']':
			open = '['
		case '}':
			open = '{'
		default:
			stack = append(stack, c)
			continue
		}
		if len(stack) == 0 || stack[len(stack)-1] != open {
			return false
		}
		stack = stack[:len(stack)-1]
	}
	return len(stack) == 0
}
