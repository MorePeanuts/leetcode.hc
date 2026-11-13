class Solution:
    def findRedundantConnection(self, edges):
        parent = list(range(len(edges) + 1))
        size = [1] * (len(edges) + 1)
        def find(x):
            while parent[x] != x:
                parent[x] = parent[parent[x]]
                x = parent[x]
            return x
        for a,b in edges:
            x,y = find(a),find(b)
            if x == y:
                return [a,b]
            if size[x] < size[y]:
                x,y = y,x
            parent[y] = x
            size[x] += size[y]
        return []
