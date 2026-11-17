function isBipartite(graph: number[][]): boolean {
    let n = graph.length;
    const color = new Int8Array(n);
    const stack = new Int32Array(n);
    for (let start = 0; start < n; start++) {
        if (color[start] !== 0) continue;
        color[start] = 1;
        let count = 1;
        stack[0] = start;
        while (count > 0) {
            let node = stack[--count];
            for (const neighbor of graph[node]) {
                if (color[neighbor] === color[node]) return false;
                if (color[neighbor] === 0) {
                    color[neighbor] = -color[node];
                    stack[count++] = neighbor;
                }
            }
        }
    }
    return true;
}
