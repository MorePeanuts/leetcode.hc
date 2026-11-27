typedef struct {
    int **rows;
    int *sizes;
    int count;
    int capacity;
} Rows;

static void appendRow(Rows *result, const int *values, int size) {
    if (result->count == result->capacity) {
        result->capacity = result->capacity == 0 ? 16 : result->capacity * 2;
        result->rows = realloc(result->rows, result->capacity * sizeof(*result->rows));
        result->sizes = realloc(result->sizes, result->capacity * sizeof(*result->sizes));
    }
    int *row = size == 0 ? NULL : malloc(size * sizeof(*row));
    if (size > 0) {
        memcpy(row, values, size * sizeof(*row));
    }
    result->rows[result->count] = row;
    result->sizes[result->count++] = size;
}

static void visit(int n, int start, int needed, int *path, int depth, Rows *result) {
    if (needed == 0) {
        appendRow(result, path, depth);
        return;
    }
    for (int value = start; value <= n - needed + 1; value++) {
        path[depth] = value;
        visit(n, value + 1, needed - 1, path, depth + 1, result);
    }
}

int **combine(int n, int k, int *returnSize, int **returnColumnSizes) {
    Rows result = {0};
    int path[20];
    visit(n, 1, k, path, 0, &result);
    *returnSize = result.count;
    *returnColumnSizes = result.sizes;
    return result.rows;
}
