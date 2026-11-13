package main

func multiply(num1 string, num2 string) string {
	if num1 == "0" || num2 == "0" {
		return "0"
	}
	digits := make([]int, len(num1)+len(num2))
	for i := len(num1) - 1; i >= 0; i-- {
		for j := len(num2) - 1; j >= 0; j-- {
			total := digits[i+j+1] + int(num1[i]-'0')*int(num2[j]-'0')
			digits[i+j+1] = total % 10
			digits[i+j] += total / 10
		}
	}
	start := 0
	if digits[0] == 0 {
		start = 1
	}
	out := make([]byte, len(digits)-start)
	for i := start; i < len(digits); i++ {
		out[i-start] = byte(digits[i]) + '0'
	}
	return string(out)
}
