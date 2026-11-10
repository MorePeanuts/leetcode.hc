class Solution:
    def carFleet(self, target: int, position: list[int], speed: list[int]) -> int:
        # From the car nearest the target back: a car that would arrive
        # later than the fleet ahead of it leads a new fleet, the others
        # catch up. Times are quotients of integers up to 10^6, so distinct
        # ones stay distinct as floats, and equal ones are equal.
        fleets = 0
        slowest = 0.0
        for p, s in sorted(zip(position, speed), reverse=True):
            t = (target - p) / s
            if t > slowest:
                fleets += 1
                slowest = t
        return fleets
