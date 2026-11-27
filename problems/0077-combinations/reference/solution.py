from itertools import combinations


class Solution:
    def combine(self, n: int, k: int) -> list[list[int]]:
        return [list(row) for row in combinations(range(1, n + 1), k)]
