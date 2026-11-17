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

static int compare(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    return (x > y) - (x < y);
}

static void visit(const int* values, int size, Rows* result, int* path, int len, int start) {
    appendRow(result, path, len);
    for (int i = start; i < size; ++i) {
        int value = values[i];

        if (i > start && value == values[i - 1]) {
            continue;
        }
        path[len] = value;
        visit(values, size, result, path, len + 1, i + 1);

    }
}

int** subsetsWithDup(int* values, int size, int* returnSize, int** returnColumnSizes) {
    qsort(values, (size_t)size, sizeof(*values), compare);
    Rows result = {0};
    int* path = malloc((size_t)(size) * sizeof(*path));
    visit(values, size, &result, path, 0, 0);
    free(path);
    *returnSize = result.count;
    *returnColumnSizes = result.sizes;
    return result.rows;
}
