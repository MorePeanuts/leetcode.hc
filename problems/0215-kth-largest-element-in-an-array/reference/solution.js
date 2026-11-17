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

function findKthLargest(nums, k) {
    const heap = [];
    for (let i = 0; i < k; i++) {
        push(heap, nums[i]);
    }
    for (let i = k; i < nums.length; i++) {
        if (nums[i] > heap[0]) {
            siftDown(heap, nums[i]);
        }
    }
    return heap[0];
}
