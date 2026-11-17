int *countBits(int n, int *returnSize) {
    *returnSize = n + 1;
    int *result = malloc(*returnSize * sizeof(*result));
    result[0] = 0;
    for (int value = 1; value <= n; value++) {
        result[value] = result[value >> 1] + (value & 1);
    }
    return result;
}
