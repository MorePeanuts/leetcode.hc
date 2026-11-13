class Solution:
    def carPooling(self, trips: list[list[int]], capacity: int) -> bool:
        difference = [0] * 1001
        for passengers, start, end in trips:
            difference[start] += passengers
            difference[end] -= passengers
        onboard = 0
        for change in difference:
            onboard += change
            if onboard > capacity:
                return False
        return True
