package main

func corpFlightBookings(bookings [][]int, n int) []int {
	difference := make([]int, n+1)
	for _, b := range bookings {
		difference[b[0]-1] += b[2]
		difference[b[1]] -= b[2]
	}
	answer := make([]int, n)
	running := 0
	for i := range answer {
		running += difference[i]
		answer[i] = running
	}
	return answer
}
