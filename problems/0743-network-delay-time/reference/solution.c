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

int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k) {
    int edges = timesSize;
    int* first = calloc((size_t)(n + 1), sizeof(*first));
    int* next = calloc((size_t)(edges), sizeof(*next));
    int* distance = calloc((size_t)(n + 1), sizeof(*distance));
    int unreachable = 1000000000;
    for (int i = 1; i <= n; ++i) {
        first[i] = -1;
        distance[i] = unreachable;
    }
    for (int i = 0; i < edges; ++i) {
        int from = times[i][0];
        next[i] = first[from];
        first[from] = i;
    }
    Heap queue = {0};
    distance[k] = 0;
    push(&queue, 0, k);
    while (queue.size > 0) {
        Entry entry = pop(&queue);
        int node = entry.value;
        int cost = (int)entry.priority;
        if (cost != distance[node]) {
            continue;
        }
        for (int edge = first[node]; edge >= 0; edge = next[edge]) {
            int to = times[edge][1];
            int candidate = cost + times[edge][2];
            if (candidate < distance[to]) {
                distance[to] = candidate;
                push(&queue, candidate, to);
            }
        }
    }
    int answer = 0;
    for (int i = 1; i <= n; ++i) {
        if (distance[i] > answer) {
            answer = distance[i];
        }
    }
    free(queue.entries);
    free(first);
    free(next);
    free(distance);
    return answer == unreachable ? -1 : answer;
}
