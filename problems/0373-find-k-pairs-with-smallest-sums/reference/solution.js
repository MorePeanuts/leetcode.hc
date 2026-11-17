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

function kSmallestPairs(nums1, nums2, k) {
    let rows = nums1.length;
    let cols = nums2.length;
    let seeds = rows < k ? rows : k;
    const queue = new MinQueue();
    for (let i = 0; i < seeds; ++i) {
        queue.push(nums1[i] + nums2[0], i * cols);
    }
    const result = [];
    for (let count = 0; count < k; ++count) {
        const entry = queue.pop();
        let id = entry.value;
        let i = Math.floor(id / cols);
        let j = id % cols;
        result.push([nums1[i], nums2[j]]);
        if (j + 1 < cols) {
            queue.push(nums1[i] + nums2[j + 1], id + 1);
        }
    }

    return result;
}
