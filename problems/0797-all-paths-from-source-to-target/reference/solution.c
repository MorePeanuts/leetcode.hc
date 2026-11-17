typedef struct {
    int** rows;
    int* sizes;
    int count;
    int capacity;
} Rows;

static void appendRow(Rows* result, const int* path, int len) {
    if (result->count == result->capacity) {
        result->capacity = result->capacity ? 2 * result->capacity : 8;
        result->rows = realloc(result->rows, (size_t)result->capacity * sizeof(*result->rows));
        result->sizes = realloc(result->sizes, (size_t)result->capacity * sizeof(*result->sizes));
    }
    int* copy = malloc((size_t)len * sizeof(*copy));
    if (len > 0) {
        memcpy(copy, path, (size_t)len * sizeof(*copy));
    }
    result->rows[result->count] = copy;
    result->sizes[result->count++] = len;
}

static void visit(int** graph, int size, const int* widths, Rows* result, int* path, int len, int node) {
    if (node == size - 1) {
        appendRow(result, path, len);
        return;
    }
    for (int i = 0; i < widths[node]; ++i) {
        int value = graph[node][i];
        path[len] = value;
        visit(graph, size, widths, result, path, len + 1, value);

    }
}

int** allPathsSourceTarget(int** graph, int size, int* widths, int* returnSize, int** returnColumnSizes) {

    Rows result = {0};
    int* path = malloc((size_t)(size) * sizeof(*path));
    path[0] = 0;
    visit(graph, size, widths, &result, path, 1, 0);
    free(path);
    *returnSize = result.count;
    *returnColumnSizes = result.sizes;
    return result.rows;
}
