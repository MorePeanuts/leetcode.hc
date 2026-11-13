class Solution:
    def minCostConnectPoints(self, points: list[list[int]]) -> int:
        n = len(points)
        best = [float('inf')] * n
        best[0] = 0
        used = [False] * n
        total = 0
        for _ in range(n):
            vertex = -1
            for i in range(n):
                if not used[i] and (vertex < 0 or best[i] < best[vertex]):
                    vertex = i
            used[vertex] = True
            total += best[vertex]
            x, y = points[vertex]
            for i, (other_x, other_y) in enumerate(points):
                if not used[i]:
                    distance = abs(x - other_x) + abs(y - other_y)
                    if distance < best[i]:
                        best[i] = distance
        return total
