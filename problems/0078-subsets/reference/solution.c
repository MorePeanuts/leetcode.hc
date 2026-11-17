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

static void visit(int *nums, int n, int *path, int size, int start, Rows *result) {
    appendRow(result, path, size);
    for (int i = start; i < n; i++) {
        path[size] = nums[i];
        visit(nums, n, path, size + 1, i + 1, result);
    }
}

int **subsets(int *nums, int n, int *returnSize, int **returnColumnSizes) {
    int path[n];
    Rows result = {0};
    visit(nums, n, path, 0, 0, &result);
    *returnSize = result.count;
    *returnColumnSizes = result.sizes;
    return result.rows;
}
