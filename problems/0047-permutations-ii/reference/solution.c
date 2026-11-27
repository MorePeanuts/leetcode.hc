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

static void visit(int *nums, int n, int start, Rows *result) {
    if (start == n) {
        appendRow(result, nums, n);
        return;
    }
    bool used[21] = {false};
    for (int i = start; i < n; i++) {
        int key = nums[i] + 10;
        if (used[key]) {
            continue;
        }
        used[key] = true;
        int value = nums[start];
        nums[start] = nums[i];
        nums[i] = value;
        visit(nums, n, start + 1, result);
        nums[i] = nums[start];
        nums[start] = value;
    }
}

int **permuteUnique(int *nums, int n, int *returnSize, int **returnColumnSizes) {
    Rows result = {0};
    visit(nums, n, 0, &result);
    *returnSize = result.count;
    *returnColumnSizes = result.sizes;
    return result.rows;
}
