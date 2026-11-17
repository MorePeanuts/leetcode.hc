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

function leastInterval(tasks: string[], n: number): number {
    let length = tasks.length;
    const counts = new Int32Array(26);
    const coolingCounts = new Int32Array(length);
    const coolingUntil = new Int32Array(length);
    for (let i = 0; i < length; ++i) {
        ++counts[tasks[i].charCodeAt(0) - 65];
    }
    const queue = new MinQueue();
    for (let i = 0; i < 26; ++i) {
        if (counts[i] > 0) {
            queue.push(-counts[i], counts[i]);
        }
    }
    let time = 0;
    let head = 0;
    let tail = 0;
    while (queue.entries.length > 0 || head < tail) {
        ++time;
        if (queue.entries.length > 0) {
            const entry = queue.pop();
            let remaining = entry.value - 1;
            if (remaining > 0) {
                coolingCounts[tail] = remaining;
                coolingUntil[tail++] = time + n;
            }
        } else {
            time = coolingUntil[head];
        }
        if (head < tail && coolingUntil[head] === time) {
            let ready = coolingCounts[head++];
            queue.push(-ready, ready);
        }
    }




    return time;
}
