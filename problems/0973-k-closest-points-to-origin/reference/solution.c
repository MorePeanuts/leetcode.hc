#include <stdlib.h>

static int distance(const int* point) {
    return point[0] * point[0] + point[1] * point[1];
}

static int compare(const void* lhs, const void* rhs) {
    int a = distance(*(int* const*)lhs);
    int b = distance(*(int* const*)rhs);
    return (a > b) - (a < b);
}

int** kClosest(int** points, int pointsSize, int* pointsColSize, int k,
                int* returnSize, int** returnColumnSizes) {
    qsort(points, (size_t)pointsSize, sizeof(*points), compare);
    *returnSize = k;
    *returnColumnSizes = pointsColSize; // Each row has two coordinates.
    return points;
}
