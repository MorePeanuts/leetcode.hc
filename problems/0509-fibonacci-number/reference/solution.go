package main

func fib(n int) int {
	current, following := 0, 1
	for i := 0; i < n; i++ {
		current, following = following, current+following
	}
	return current
}
