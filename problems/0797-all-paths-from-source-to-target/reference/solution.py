class Solution:
    def allPathsSourceTarget(self, graph: list[list[int]]) -> list[list[int]]:
        result = []
        path = [0]

        def visit(node):
            if node == len(graph) - 1:
                result.append(path.copy())
                return
            for neighbor in graph[node]:
                path.append(neighbor)
                visit(neighbor)
                path.pop()

        visit(0)
        return result
