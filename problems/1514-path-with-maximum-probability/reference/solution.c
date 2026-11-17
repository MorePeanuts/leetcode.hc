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

double maxProbability(int n, int** edges, int edgesSize, int* edgesColSize, double* succProb, int succProbSize, int startNode, int endNode) {
    int m = edgesSize;
    int* first = calloc((size_t)(n), sizeof(*first));
    int* next = calloc((size_t)(2 * m), sizeof(*next));
    int* to = calloc((size_t)(2 * m), sizeof(*to));
    double* best = calloc((size_t)(n), sizeof(*best));
    for (int node = 0; node < n; ++node) {
        first[node] = -1;
    }
    for (int i = 0; i < m; ++i) {
        for (int dir = 0; dir < 2; ++dir) {
            int from = edges[i][dir];
            int edge = 2 * i + dir;
            to[edge] = edges[i][1 - dir];
            next[edge] = first[from];
            first[from] = edge;
        }
    }
    Heap queue = {0};
    best[startNode] = 1;
    push(&queue, -1, startNode);
    while (queue.size > 0) {
        Entry entry = pop(&queue);
        int node = entry.value;
        double probability = -entry.priority;
        if (probability < best[node]) {
            continue;
        }
        if (node == endNode) {
            break;
        }
        for (int edge = first[node]; edge >= 0; edge = next[edge]) {
            double candidate = probability * succProb[edge / 2];
            int neighbor = to[edge];
            if (candidate > best[neighbor]) {
                best[neighbor] = candidate;
                push(&queue, -candidate, neighbor);
            }
        }
    }
    double answer = best[endNode];
    free(queue.entries);
    free(first);
    free(next);
    free(to);
    free(best);
    return answer;
}
