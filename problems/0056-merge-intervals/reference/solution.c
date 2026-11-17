#include <stdlib.h>

static int byStart(const void* lhs, const void* rhs) {
    int a = (*(int* const*)lhs)[0];
    int b = (*(int* const*)rhs)[0];
    return (a > b) - (a < b);
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize,
            int* returnSize, int** returnColumnSizes) {
    qsort(intervals, (size_t)intervalsSize, sizeof(*intervals), byStart);
    int** result = malloc((size_t)intervalsSize * sizeof(*result));
    int* cols = malloc((size_t)intervalsSize * sizeof(*cols));
    int count = 0;
    for (int i = 0; i < intervalsSize; i++) {
        int* interval = intervals[i];
        if (count > 0 && interval[0] <= result[count - 1][1]) {
            if (interval[1] > result[count - 1][1]) result[count - 1][1] = interval[1];
        } else {
            result[count] = interval;
            cols[count++] = 2;
        }
    }
    *returnSize = count;
    *returnColumnSizes = cols;
    return result;
}
