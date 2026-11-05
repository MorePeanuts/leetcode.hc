package main

// Walks from the last day back, keeping a stack of the days after i whose
// temperatures strictly increase from the top: the Python reference walks
// forward instead.
func dailyTemperatures(temperatures []int) []int {
	n := len(temperatures)
	answer := make([]int, n)
	stack := make([]int, 0, n)
	for i := n - 1; i >= 0; i-- {
		for len(stack) > 0 && temperatures[stack[len(stack)-1]] <= temperatures[i] {
			stack = stack[:len(stack)-1]
		}
		if len(stack) > 0 {
			answer[i] = stack[len(stack)-1] - i
		}
		stack = append(stack, i)
	}
	return answer
}
