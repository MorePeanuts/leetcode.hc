int **insert(int **intervals, int n, int *columnSizes, int *newInterval, int newIntervalSize, int *returnSize, int **returnColumnSizes) {
    (void)columnSizes;
    (void)newIntervalSize;
    int **result = malloc((n + 1) * sizeof(*result));
    int *sizes = malloc((n + 1) * sizeof(*sizes));
    int count = 0;
    int low = newInterval[0];
    int high = newInterval[1];
    int i = 0;
    while (i < n && intervals[i][1] < low) {
        int *row = malloc(2 * sizeof(*row));
        memcpy(row, intervals[i++], 2 * sizeof(*row));
        result[count++] = row;
    }
    while (i < n && intervals[i][0] <= high) {
        if (intervals[i][0] < low) {
            low = intervals[i][0];
        }
        if (intervals[i][1] > high) {
            high = intervals[i][1];
        }
        i++;
    }
    int *merged = malloc(2 * sizeof(*merged));
    merged[0] = low;
    merged[1] = high;
    result[count++] = merged;
    while (i < n) {
        int *row = malloc(2 * sizeof(*row));
        memcpy(row, intervals[i++], 2 * sizeof(*row));
        result[count++] = row;
    }
    for (int j = 0; j < count; j++) {
        sizes[j] = 2;
    }
    *returnSize = count;
    *returnColumnSizes = sizes;
    return result;
}
