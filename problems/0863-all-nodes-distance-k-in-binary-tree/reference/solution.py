class Solution:
    def distanceK(self, root, target, k):
        parents = {root: None}
        nodes = [root]
        for node in nodes:
            for child in (node.left, node.right):
                if child:
                    parents[child] = node
                    nodes.append(child)
        frontier = [target]
        seen = {target}
        for _ in range(k):
            next_frontier = []
            for node in frontier:
                for other in (node.left, node.right, parents[node]):
                    if other and other not in seen:
                        seen.add(other)
                        next_frontier.append(other)
            frontier = next_frontier
            if not frontier:
                break
        return [node.val for node in frontier]
