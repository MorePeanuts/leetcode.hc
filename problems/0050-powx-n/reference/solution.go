package main

func myPow(x float64, n int) float64 {
	exponent := int64(n)
	if exponent < 0 {
		x = 1 / x
		exponent = -exponent
	}
	result := 1.0
	for exponent > 0 {
		if exponent&1 == 1 {
			result *= x
		}
		exponent >>= 1
		if exponent > 0 {
			x *= x
		}
	}
	return result
}
