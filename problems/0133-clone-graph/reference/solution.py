from hc_runtime import GraphNode as Node

class Solution:
    def cloneGraph(self, node):
        if node is None:
            return None
        copies = {node: Node(node.val)}
        queue = [node]
        for current in queue:
            for neighbor in current.neighbors:
                if neighbor not in copies:
                    copies[neighbor] = Node(neighbor.val)
                    queue.append(neighbor)
                copies[current].neighbors.append(copies[neighbor])
        return copies[node]
