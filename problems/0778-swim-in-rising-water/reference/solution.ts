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

function swimInWater(grid: number[][]): number {
    let n = grid.length;
    const dr = [1, -1, 0, 0];
    const dc = [0, 0, 1, -1];
    const best = new Int32Array(n * n);
    for (let i = 0; i < n * n; ++i) {
        best[i] = n * n;
    }
    const queue = new MinQueue();
    best[0] = grid[0][0];
    queue.push(best[0], 0);
    let answer = -1;
    while (queue.entries.length > 0) {
        const entry = queue.pop();
        let node = entry.value;
        let time = entry.priority;
        if (time !== best[node]) {
            continue;
        }
        if (node === n * n - 1) {
            answer = time;
            break;
        }
        let row = Math.floor(node / n);
        let col = node % n;
        for (let d = 0; d < 4; ++d) {
            let nr = row + dr[d];
            let nc = col + dc[d];
            if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                let next = nr * n + nc;
                let candidate = time > grid[nr][nc] ? time : grid[nr][nc];
                if (candidate < best[next]) {
                    best[next] = candidate;
                    queue.push(candidate, next);
                }
            }
        }
    }


    return answer;
}
