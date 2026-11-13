class Solution:
    def corpFlightBookings(self, bookings: list[list[int]], n: int) -> list[int]:
        difference = [0] * (n + 1)
        for first, last, seats in bookings:
            difference[first - 1] += seats
            difference[last] -= seats
        answer = []
        running = 0
        for i in range(n):
            running += difference[i]
            answer.append(running)
        return answer
