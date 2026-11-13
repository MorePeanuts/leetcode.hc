from collections import Counter

class Solution:
    def isNStraightHand(self, hand: list[int], groupSize: int) -> bool:
        if len(hand) % groupSize:
            return False
        counts = Counter(hand)
        for first in sorted(counts):
            amount = counts[first]
            if amount == 0:
                continue
            for value in range(first, first + groupSize):
                if counts[value] < amount:
                    return False
                counts[value] -= amount
        return True
