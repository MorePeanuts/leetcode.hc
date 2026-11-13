package main

func numTrees(n int) int {
	// Consecutive Catalan numbers; the product needs a 64-bit intermediate.
	count := int64(1)
	for k := int64(0); k < int64(n); k++ {
		count = count * (4*k + 2) / (k + 2)
	}
	return int(count)
}
