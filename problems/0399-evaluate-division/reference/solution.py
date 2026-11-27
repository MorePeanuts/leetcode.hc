from collections import defaultdict, deque


class Solution:
    def calcEquation(self, equations: list[list[str]], values: list[float],
                     queries: list[list[str]]) -> list[float]:
        graph = defaultdict(list)
        for (a, b), ratio in zip(equations, values):
            graph[a].append((b, ratio))
            graph[b].append((a, 1.0 / ratio))

        def quotient(start, target):
            if start not in graph or target not in graph:
                return -1.0
            seen = {start}
            queue = deque([(start, 1.0)])
            while queue:
                node, product = queue.popleft()
                if node == target:
                    return product
                for neighbor, ratio in graph[node]:
                    if neighbor not in seen:
                        seen.add(neighbor)
                        queue.append((neighbor, product * ratio))
            return -1.0

        return [quotient(a, b) for a, b in queries]
