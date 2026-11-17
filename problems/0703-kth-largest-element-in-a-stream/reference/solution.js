function siftDown(heap, value) {
    let index = 0;
    while (2 * index + 1 < heap.length) {
        let child = 2 * index + 1;
        if (child + 1 < heap.length && heap[child + 1] < heap[child]) {
            child++;
        }
        if (heap[child] >= value) {
            break;
        }
        heap[index] = heap[child];
        index = child;
    }
    heap[index] = value;
}

function push(heap, value) {
    let index = heap.length;
    while (index > 0) {
        const parent = Math.floor((index - 1) / 2);
        if (heap[parent] <= value) {
            break;
        }
        heap[index] = heap[parent];
        index = parent;
    }
    heap[index] = value;
}

class KthLargest {
    heap = [];
    k;

    constructor(k, nums) {
        this.k = k;
        for (const value of nums) {
            this.add(value);
        }
    }

    add(val) {
        if (this.heap.length < this.k) {
            push(this.heap, val);
        } else if (val > this.heap[0]) {
            siftDown(this.heap, val);
        }
        return this.heap[0];
    }
}
