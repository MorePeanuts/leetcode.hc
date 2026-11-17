struct Entry {
    int position;
    int cost;
};

static void push(struct Entry *queue, int size, struct Entry value) {
    int index = size;
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (queue[parent].cost <= value.cost) {
            break;
        }
        queue[index] = queue[parent];
        index = parent;
    }
    queue[index] = value;
}

static struct Entry pop(struct Entry *queue, int *size) {
    struct Entry result = queue[0];
    struct Entry last = queue[--*size];
    int index = 0;
    while (2 * index + 1 < *size) {
        int child = 2 * index + 1;
        if (child + 1 < *size && queue[child + 1].cost < queue[child].cost) {
            child++;
        }
        if (last.cost <= queue[child].cost) {
            break;
        }
        queue[index] = queue[child];
        index = child;
    }
    queue[index] = last;
    return result;
}


int minimumEffortPath(int **heights, int rows, int *columnSizes) {
    int cols = columnSizes[0];
    int total = rows * cols;
    int best[total];
    for (int i = 0; i < total; i++) {
        best[i] = INT_MAX;
    }
    struct Entry *queue = malloc((4 * total + 1) * sizeof(*queue));
    int size = 0;
    best[0] = 0;
    push(queue, size++, (struct Entry){0, 0});
    const int dr[] = {-1, 1, 0, 0};
    const int dc[] = {0, 0, -1, 1};
    while (size > 0) {
        struct Entry entry = pop(queue, &size);
        int position = entry.position;
        int cost = entry.cost;
        if (cost != best[position]) {
            continue;
        }
        if (position == total - 1) {
            free(queue);
            return cost;
        }
        int r = position / cols;
        int c = position % cols;
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) {
                continue;
            }
            int next = nr * cols + nc;
            int difference = abs(heights[r][c] - heights[nr][nc]);
            int candidate = cost > difference ? cost : difference;
            if (candidate < best[next]) {
                best[next] = candidate;
                push(queue, size++, (struct Entry){next, candidate});
            }
        }
    }
    free(queue);
    return 0;
}
