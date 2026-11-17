struct Partitions {
    char ***rows;
    int *sizes;
    int count;
    int capacity;
};

static void visit(const char *s, int n, bool palindrome[][16], int *ends,
                  int size, int start, struct Partitions *result) {
    if (start == n) {
        if (result->count == result->capacity) {
            result->capacity = result->capacity == 0 ? 16 : result->capacity * 2;
            result->rows = realloc(result->rows, result->capacity * sizeof(*result->rows));
            result->sizes = realloc(result->sizes, result->capacity * sizeof(*result->sizes));
        }
        char **row = malloc(size * sizeof(*row));
        int left = 0;
        for (int i = 0; i < size; i++) {
            int length = ends[i] - left;
            row[i] = malloc(length + 1);
            memcpy(row[i], s + left, length);
            row[i][length] = '\0';
            left = ends[i];
        }
        result->rows[result->count] = row;
        result->sizes[result->count++] = size;
        return;
    }
    for (int end = start; end < n; end++) {
        if (palindrome[start][end]) {
            ends[size] = end + 1;
            visit(s, n, palindrome, ends, size + 1, end + 1, result);
        }
    }
}

char ***partition(char *s, int *returnSize, int **returnColumnSizes) {
    int n = strlen(s);
    bool palindrome[16][16] = {0};
    for (int left = n - 1; left >= 0; left--) {
        for (int right = left; right < n; right++) {
            palindrome[left][right] = s[left] == s[right] &&
                (right - left < 2 || palindrome[left + 1][right - 1]);
        }
    }
    struct Partitions result = {0};
    int ends[16];
    visit(s, n, palindrome, ends, 0, 0, &result);
    *returnSize = result.count;
    *returnColumnSizes = result.sizes;
    return result.rows;
}
