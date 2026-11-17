int* findMinHeightTrees(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    int edgeCount = edgesSize;
    int* first = calloc((size_t)(n), sizeof(*first));
    int* neighbor = calloc((size_t)(2 * edgeCount), sizeof(*neighbor));
    int* next = calloc((size_t)(2 * edgeCount), sizeof(*next));
    int* degree = calloc((size_t)(n), sizeof(*degree));
    int* queue = calloc((size_t)(n), sizeof(*queue));
    for (int node = 0; node < n; ++node) {
        first[node] = -1;
    }
    for (int edge = 0; edge < edgeCount; ++edge) {
        for (int direction = 0; direction < 2; ++direction) {
            int from = edges[edge][direction];
            int slot = 2 * edge + direction;
            neighbor[slot] = edges[edge][1 - direction];
            next[slot] = first[from];
            first[from] = slot;
            ++degree[from];
        }
    }

    int head = 0;
    int tail = 0;
    for (int node = 0; node < n; ++node) {
        if (degree[node] <= 1) {
            queue[tail++] = node;
        }
    }
    int remaining = n;
    while (remaining > 2) {
        int layerEnd = tail;
        remaining -= layerEnd - head;
        while (head < layerEnd) {
            int leaf = queue[head++];
            for (int edge = first[leaf]; edge >= 0; edge = next[edge]) {
                int adjacent = neighbor[edge];
                if (--degree[adjacent] == 1) {
                    queue[tail++] = adjacent;
                }
            }
        }
    }
    *returnSize = tail - head;
    int* result = malloc((size_t)*returnSize * sizeof(*result));
    memcpy(result, queue + head, (size_t)*returnSize * sizeof(*result));
    free(first);
    free(neighbor);
    free(next);
    free(degree);
    free(queue);
    return result;
}
