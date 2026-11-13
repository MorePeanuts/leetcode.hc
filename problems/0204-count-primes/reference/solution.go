package main

func countPrimes(n int) int {
	if n < 3 {
		return 0
	}
	composite := make([]bool, n)
	count := 0
	for p := 2; p < n; p++ {
		if composite[p] {
			continue
		}
		count++
		if p*p < n {
			for q := p * p; q < n; q += p {
				composite[q] = true
			}
		}
	}
	return count
}
