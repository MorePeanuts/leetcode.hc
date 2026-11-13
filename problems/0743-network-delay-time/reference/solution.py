from heapq import heappop, heappush


class Solution:
    def networkDelayTime(self, times: list[list[int]], n: int, k: int) -> int:
        edges = [[] for _ in range(n + 1)]
        for u, v, w in times:
            edges[u].append((v, w))
        distance = [float('inf')] * (n + 1)
        distance[k] = 0
        queue = [(0, k)]
        while queue:
            cost, u = heappop(queue)
            if cost != distance[u]:
                continue
            for v, weight in edges[u]:
                candidate = cost + weight
                if candidate < distance[v]:
                    distance[v] = candidate
                    heappush(queue, (candidate, v))
        answer = max(distance[1:])
        return -1 if answer == float('inf') else answer
