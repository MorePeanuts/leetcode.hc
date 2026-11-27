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

static void visit(int start, int needed, int remaining, int *path, int depth, Rows *result) {
    if (needed == 0) {
        if (remaining == 0) {
            appendRow(result, path, depth);
        }
        return;
    }
    for (int value = start; value <= 9 - needed + 1 && value <= remaining; value++) {
        path[depth] = value;
        visit(value + 1, needed - 1, remaining - value, path, depth + 1, result);
    }
}

int **combinationSum3(int k, int n, int *returnSize, int **returnColumnSizes) {
    Rows result = {0};
    int path[9];
    visit(1, k, n, path, 0, &result);
    *returnSize = result.count;
    *returnColumnSizes = result.sizes;
    return result.rows;
}
