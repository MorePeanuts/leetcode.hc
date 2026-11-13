package main

func isHappy(n int) bool {
	step := func(v int) int {
		sum := 0
		for v > 0 {
			d := v % 10
			sum += d * d
			v /= 10
		}
		return sum
	}
	slow, fast := n, step(n)
	for fast != 1 && slow != fast {
		slow = step(slow)
		fast = step(step(fast))
	}
	return fast == 1
}
