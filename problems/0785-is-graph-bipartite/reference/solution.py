class Solution:
    def isBipartite(self, graph: list[list[int]]) -> bool:
        colors = [0] * len(graph)
        for start in range(len(graph)):
            if colors[start]:
                continue
            colors[start] = 1
            stack = [start]
            while stack:
                node = stack.pop()
                for neighbor in graph[node]:
                    if colors[neighbor] == colors[node]:
                        return False
                    if not colors[neighbor]:
                        colors[neighbor] = -colors[node]
                        stack.append(neighbor)
        return True
