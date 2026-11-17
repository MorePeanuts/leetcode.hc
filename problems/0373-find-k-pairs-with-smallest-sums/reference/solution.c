typedef struct {
    double priority;
    int value;
} Entry;

typedef struct {
    Entry* entries;
    int size;
    int capacity;
} Heap;

static void push(Heap* heap, double priority, int value) {
    if (heap->size == heap->capacity) {
        heap->capacity = heap->capacity == 0 ? 8 : 2 * heap->capacity;
        heap->entries = realloc(heap->entries, (size_t)heap->capacity * sizeof(*heap->entries));
    }
    int child = heap->size++;
    while (child > 0) {
        int parent = (child - 1) / 2;
        if (heap->entries[parent].priority <= priority) {
            break;
        }
        heap->entries[child] = heap->entries[parent];
        child = parent;
    }
    heap->entries[child] = (Entry){priority, value};
}

static Entry pop(Heap* heap) {
    Entry first = heap->entries[0];
    Entry last = heap->entries[--heap->size];
    if (heap->size == 0) {
        return first;
    }
    int parent = 0;
    while (2 * parent + 1 < heap->size) {
        int child = 2 * parent + 1;
        if (child + 1 < heap->size && heap->entries[child + 1].priority < heap->entries[child].priority) {
            ++child;
        }
        if (last.priority <= heap->entries[child].priority) {
            break;
        }
        heap->entries[parent] = heap->entries[child];
        parent = child;
    }
    heap->entries[parent] = last;
    return first;
}

int** kSmallestPairs(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize, int** returnColumnSizes) {
    int rows = nums1Size;
    int cols = nums2Size;
    int seeds = rows < k ? rows : k;
    Heap queue = {0};
    for (int i = 0; i < seeds; ++i) {
        push(&queue, nums1[i] + nums2[0], i * cols);
    }
    int** result = malloc((size_t)k * sizeof(*result));
    *returnSize = k;
    *returnColumnSizes = malloc((size_t)k * sizeof(**returnColumnSizes));
    for (int count = 0; count < k; ++count) {
        Entry entry = pop(&queue);
        int id = entry.value;
        int i = id / cols;
        int j = id % cols;
        result[count] = malloc(2 * sizeof(*result[count]));
        result[count][0] = nums1[i];
        result[count][1] = nums2[j];
        (*returnColumnSizes)[count] = 2;
        if (j + 1 < cols) {
            push(&queue, nums1[i] + nums2[j + 1], id + 1);
        }
    }
    free(queue.entries);
    return result;
}
