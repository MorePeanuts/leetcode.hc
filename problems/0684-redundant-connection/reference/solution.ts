function findRedundantConnection(edges: number[][]): number[] {
    const parent = Int32Array.from({length: edges.length + 1}, (_, i) => i);
    const size = new Int32Array(edges.length + 1).fill(1);

    function find(node: number) {
        while (parent[node] !== node) {
            parent[node] = parent[parent[node]];
            node = parent[node];
        }
        return node;
    }

    for (const edge of edges) {
        let a = find(edge[0]);
        let b = find(edge[1]);
        if (a === b) return edge;
        if (size[a] < size[b]) [a, b] = [b, a];
        parent[b] = a;
        size[a] += size[b];
    }
    return [];
}
