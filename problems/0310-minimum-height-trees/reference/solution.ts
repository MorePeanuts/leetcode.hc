function findMinHeightTrees(n: number, edges: number[][]): number[] {
    let edgeCount = edges.length;
    const first = new Int32Array(n);
    const neighbor = new Int32Array(2 * edgeCount);
    const next = new Int32Array(2 * edgeCount);
    const degree = new Int32Array(n);
    const queue = new Int32Array(n);
    for (let node = 0; node < n; ++node) {
        first[node] = -1;
    }
    for (let edge = 0; edge < edgeCount; ++edge) {
        for (let direction = 0; direction < 2; ++direction) {
            let from = edges[edge][direction];
            let slot = 2 * edge + direction;
            neighbor[slot] = edges[edge][1 - direction];
            next[slot] = first[from];
            first[from] = slot;
            ++degree[from];
        }
    }

    let head = 0;
    let tail = 0;
    for (let node = 0; node < n; ++node) {
        if (degree[node] <= 1) {
            queue[tail++] = node;
        }
    }
    let remaining = n;
    while (remaining > 2) {
        let layerEnd = tail;
        remaining -= layerEnd - head;
        while (head < layerEnd) {
            let leaf = queue[head++];
            for (let edge = first[leaf]; edge >= 0; edge = next[edge]) {
                let adjacent = neighbor[edge];
                if (--degree[adjacent] === 1) {
                    queue[tail++] = adjacent;
                }
            }
        }
    }
    return Array.from(queue.subarray(head, tail));
}
