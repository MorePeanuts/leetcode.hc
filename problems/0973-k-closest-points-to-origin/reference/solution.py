class Solution:
    # Sort by squared distance and take the first k, closest first.
    def kClosest(self, points: list[list[int]], k: int) -> list[list[int]]:
        return sorted(points, key=lambda p: p[0] * p[0] + p[1] * p[1])[:k]
