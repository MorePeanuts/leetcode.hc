class Solution:
    def canCompleteCircuit(self, gas: list[int], cost: list[int]) -> int:
        total = tank = start = 0
        for index, (supply, expense) in enumerate(zip(gas, cost)):
            total += supply - expense
            tank += supply - expense
            if tank < 0:
                start = index + 1
                tank = 0
        return start if total >= 0 else -1
