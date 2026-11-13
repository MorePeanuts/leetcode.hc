from heapq import heappop, heappush


class Solution:
    def maxProbability(self, n: int, edges: list[list[int]], succProb: list[float], start_node: int, end_node: int) -> float:
        graph = [[] for _ in range(n)]
        for (a, b), probability in zip(edges, succProb):
            graph[a].append((b, probability))
            graph[b].append((a, probability))
        best = [0.0] * n
        best[start_node] = 1.0
        heap = [(-1.0, start_node)]
        while heap:
            negative, node = heappop(heap)
            probability = -negative
            if probability < best[node]:
                continue
            if node == end_node:
                return probability
            for neighbor, chance in graph[node]:
                candidate = probability * chance
                if candidate > best[neighbor]:
                    best[neighbor] = candidate
                    heappush(heap, (-candidate, neighbor))
        return 0.0
