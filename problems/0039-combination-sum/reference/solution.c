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

static int compareInt(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

static void visit(int *nums, int n, int *path, int size, int start, int remaining, Rows *result) {
    if (remaining == 0) {
        appendRow(result, path, size);
        return;
    }
    for (int i = start; i < n; i++) {
        int value = nums[i];
        if (value > remaining) {
            break;
        }
        path[size] = value;
        visit(nums, n, path, size + 1, i, remaining - value, result);
    }
}

int **combinationSum(int *nums, int n, int target, int *returnSize, int **returnColumnSizes) {
    qsort(nums, n, sizeof(*nums), compareInt);
    int path[target / 2 + 1];
    Rows result = {0};
    visit(nums, n, path, 0, 0, target, &result);
    *returnSize = result.count;
    *returnColumnSizes = result.sizes;
    return result.rows;
}
