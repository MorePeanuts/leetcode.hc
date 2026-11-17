class MinQueue {
    readonly entries: { priority: number; value: number }[] = [];

    push(priority: number, value: number): void {
        let child = this.entries.length;
        while (child > 0) {
            const parent = (child - 1) >> 1;
            if (this.entries[parent].priority <= priority) {
                break;
            }
            this.entries[child] = this.entries[parent];
            child = parent;
        }
        this.entries[child] = { priority, value };
    }

    pop() {
        const first = this.entries[0];
        const last = this.entries.pop()!;
        if (this.entries.length === 0) {
            return first;
        }
        let parent = 0;
        while (2 * parent + 1 < this.entries.length) {
            let child = 2 * parent + 1;
            if (child + 1 < this.entries.length && this.entries[child + 1].priority < this.entries[child].priority) {
                ++child;
            }
            if (last.priority <= this.entries[child].priority) {
                break;
            }
            this.entries[parent] = this.entries[child];
            parent = child;
        }
        this.entries[parent] = last;
        return first;
    }
}

function maxProbability(n: number, edges: number[][], succProb: number[], startNode: number, endNode: number): number {
    let m = edges.length;
    const first = new Int32Array(n);
    const next = new Int32Array(2 * m);
    const to = new Int32Array(2 * m);
    const best = new Float64Array(n);
    for (let node = 0; node < n; ++node) {
        first[node] = -1;
    }
    for (let i = 0; i < m; ++i) {
        for (let dir = 0; dir < 2; ++dir) {
            let from = edges[i][dir];
            let edge = 2 * i + dir;
            to[edge] = edges[i][1 - dir];
            next[edge] = first[from];
            first[from] = edge;
        }
    }
    const queue = new MinQueue();
    best[startNode] = 1;
    queue.push(-1, startNode);
    while (queue.entries.length > 0) {
        const entry = queue.pop();
        let node = entry.value;
        let probability = -entry.priority;
        if (probability < best[node]) {
            continue;
        }
        if (node === endNode) {
            break;
        }
        for (let edge = first[node]; edge >= 0; edge = next[edge]) {
            let candidate = probability * succProb[edge >> 1];
            let neighbor = to[edge];
            if (candidate > best[neighbor]) {
                best[neighbor] = candidate;
                queue.push(-candidate, neighbor);
            }
        }
    }
    let answer = best[endNode];





    return answer;
}
