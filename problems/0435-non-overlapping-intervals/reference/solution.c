static int compareEnd(const void *a, const void *b) {
    int left = (*(int *const *)a)[1];
    int right = (*(int *const *)b)[1];
    return (left > right) - (left < right);
}

int eraseOverlapIntervals(int **intervals, int n, int *columnSizes) {
    (void)columnSizes;
    qsort(intervals, n, sizeof(*intervals), compareEnd);
    int end = INT_MIN;
    int removed = 0;
    for (int i = 0; i < n; i++) {
        if (intervals[i][0] >= end) {
            end = intervals[i][1];
        } else {
            removed++;
        }
    }
    return removed;
}
