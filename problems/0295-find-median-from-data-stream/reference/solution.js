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

class MedianFinder {
    constructor() {
        this.low = new MinQueue();
        this.high = new MinQueue();
    }

    addNum(num) {
        if (this.low.entries.length > 0 && num > -this.low.entries[0].priority) {
            this.high.push(num, num);
        } else {
            this.low.push(-num, num);
        }
        if (this.low.entries.length > this.high.entries.length + 1) {
            const entry = this.low.pop();
            this.high.push(entry.value, entry.value);
        } else if (this.high.entries.length > this.low.entries.length) {
            const entry = this.high.pop();
            this.low.push(-entry.value, entry.value);
        }
    }

    findMedian() {
        if (this.low.entries.length > this.high.entries.length) {
            return -this.low.entries[0].priority;
        }
        return (this.high.entries[0].priority - this.low.entries[0].priority) / 2;
    }
}
