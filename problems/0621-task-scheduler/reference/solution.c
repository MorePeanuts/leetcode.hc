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

int leastInterval(char* tasks, int tasksSize, int n) {
    int length = tasksSize;
    int* counts = calloc((size_t)(26), sizeof(*counts));
    int* coolingCounts = calloc((size_t)(length), sizeof(*coolingCounts));
    int* coolingUntil = calloc((size_t)(length), sizeof(*coolingUntil));
    for (int i = 0; i < length; ++i) {
        ++counts[tasks[i] - 'A'];
    }
    Heap queue = {0};
    for (int i = 0; i < 26; ++i) {
        if (counts[i] > 0) {
            push(&queue, -counts[i], counts[i]);
        }
    }
    int time = 0;
    int head = 0;
    int tail = 0;
    while (queue.size > 0 || head < tail) {
        ++time;
        if (queue.size > 0) {
            Entry entry = pop(&queue);
            int remaining = entry.value - 1;
            if (remaining > 0) {
                coolingCounts[tail] = remaining;
                coolingUntil[tail++] = time + n;
            }
        } else {
            time = coolingUntil[head];
        }
        if (head < tail && coolingUntil[head] == time) {
            int ready = coolingCounts[head++];
            push(&queue, -ready, ready);
        }
    }
    free(queue.entries);
    free(counts);
    free(coolingCounts);
    free(coolingUntil);
    return time;
}
