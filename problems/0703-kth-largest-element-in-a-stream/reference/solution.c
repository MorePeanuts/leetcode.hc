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

typedef struct {
    int *heap;
    int size;
    int k;
} KthLargest;

int kthLargestAdd(KthLargest *obj, int val) {
    if (obj->size < obj->k) {
        push(obj->heap, obj->size++, val);
    } else if (val > obj->heap[0]) {
        obj->heap[0] = val;
        siftDown(obj->heap, obj->size);
    }
    return obj->heap[0];
}

KthLargest *kthLargestCreate(int k, int *nums, int numsSize) {
    KthLargest *obj = malloc(sizeof(*obj));
    *obj = (KthLargest){.heap = malloc(k * sizeof(*obj->heap)), .k = k};
    for (int i = 0; i < numsSize; i++) {
        kthLargestAdd(obj, nums[i]);
    }
    return obj;
}

void kthLargestFree(KthLargest *obj) {
    free(obj->heap);
    free(obj);
}
