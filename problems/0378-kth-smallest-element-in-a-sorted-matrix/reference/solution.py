from heapq import heapify, heappop, heappush


class Solution:
    def kthSmallest(self, matrix: list[list[int]], k: int) -> int:
        n = len(matrix)
        heap = [(matrix[row][0], row, 0) for row in range(min(n, k))]
        heapify(heap)
        for _ in range(k):
            value, row, col = heappop(heap)
            if col + 1 < n:
                heappush(heap, (matrix[row][col + 1], row, col + 1))
        return value
