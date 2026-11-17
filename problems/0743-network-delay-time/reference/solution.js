class MinQueue {
    constructor() {
        this.entries = [];
    }

    push(priority, value) {
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
        const last = this.entries.pop();
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

function networkDelayTime(times, n, k) {
    let edges = times.length;
    const first = new Int32Array(n + 1);
    const next = new Int32Array(edges);
    const distance = new Int32Array(n + 1);
    let unreachable = 1000000000;
    for (let i = 1; i <= n; ++i) {
        first[i] = -1;
        distance[i] = unreachable;
    }
    for (let i = 0; i < edges; ++i) {
        let from = times[i][0];
        next[i] = first[from];
        first[from] = i;
    }
    const queue = new MinQueue();
    distance[k] = 0;
    queue.push(0, k);
    while (queue.entries.length > 0) {
        const entry = queue.pop();
        let node = entry.value;
        let cost = entry.priority;
        if (cost !== distance[node]) {
            continue;
        }
        for (let edge = first[node]; edge >= 0; edge = next[edge]) {
            let to = times[edge][1];
            let candidate = cost + times[edge][2];
            if (candidate < distance[to]) {
                distance[to] = candidate;
                queue.push(candidate, to);
            }
        }
    }
    let answer = 0;
    for (let i = 1; i <= n; ++i) {
        if (distance[i] > answer) {
            answer = distance[i];
        }
    }




    return answer === unreachable ? -1 : answer;
}
