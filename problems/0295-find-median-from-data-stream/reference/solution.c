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

typedef struct {
    Heap low;
    Heap high;
} MedianFinder;

MedianFinder* medianFinderCreate(void) {
    return calloc(1, sizeof(MedianFinder));
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    if (obj->low.size > 0 && num > -obj->low.entries[0].priority) {
        push(&obj->high, num, num);
    } else {
        push(&obj->low, -num, num);
    }
    if (obj->low.size > obj->high.size + 1) {
        Entry entry = pop(&obj->low);
        push(&obj->high, entry.value, entry.value);
    } else if (obj->high.size > obj->low.size) {
        Entry entry = pop(&obj->high);
        push(&obj->low, -entry.value, entry.value);
    }
}

double medianFinderFindMedian(MedianFinder* obj) {
    if (obj->low.size > obj->high.size) {
        return -obj->low.entries[0].priority;
    }
    return (obj->high.entries[0].priority - obj->low.entries[0].priority) / 2;
}

void medianFinderFree(MedianFinder* obj) {
    free(obj->low.entries);
    free(obj->high.entries);
    free(obj);
}
