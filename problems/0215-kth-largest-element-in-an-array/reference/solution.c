static void siftDown(int *heap, int size) {
    int index = 0;
    int value = heap[0];
    while (2 * index + 1 < size) {
        int child = 2 * index + 1;
        if (child + 1 < size && heap[child + 1] < heap[child]) {
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

static void push(int *heap, int size, int value) {
    int index = size;
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] <= value) {
            break;
        }
        heap[index] = heap[parent];
        index = parent;
    }
    heap[index] = value;
}

int findKthLargest(int *nums, int n, int k) {
    int *heap = malloc(k * sizeof(*heap));
    for (int i = 0; i < k; i++) {
        push(heap, i, nums[i]);
    }
    for (int i = k; i < n; i++) {
        if (nums[i] > heap[0]) {
            heap[0] = nums[i];
            siftDown(heap, k);
        }
    }
    int answer = heap[0];
    free(heap);
    return answer;
}
