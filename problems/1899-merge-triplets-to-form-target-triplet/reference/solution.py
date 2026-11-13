class Solution:
    def mergeTriplets(self, triplets: list[list[int]], target: list[int]) -> bool:
        best = [0, 0, 0]
        for triplet in triplets:
            if any(triplet[i] > target[i] for i in range(3)):
                continue
            for i in range(3):
                best[i] = max(best[i], triplet[i])
        return best == target
