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

int swimInWater(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;
    const int dr[] = {1, -1, 0, 0};
    const int dc[] = {0, 0, 1, -1};
    int* best = calloc((size_t)(n * n), sizeof(*best));
    for (int i = 0; i < n * n; ++i) {
        best[i] = n * n;
    }
    Heap queue = {0};
    best[0] = grid[0][0];
    push(&queue, best[0], 0);
    int answer = -1;
    while (queue.size > 0) {
        Entry entry = pop(&queue);
        int node = entry.value;
        int time = (int)entry.priority;
        if (time != best[node]) {
            continue;
        }
        if (node == n * n - 1) {
            answer = time;
            break;
        }
        int row = node / n;
        int col = node % n;
        for (int d = 0; d < 4; ++d) {
            int nr = row + dr[d];
            int nc = col + dc[d];
            if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                int next = nr * n + nc;
                int candidate = time > grid[nr][nc] ? time : grid[nr][nc];
                if (candidate < best[next]) {
                    best[next] = candidate;
                    push(&queue, candidate, next);
                }
            }
        }
    }
    free(queue.entries);
    free(best);
    return answer;
}
