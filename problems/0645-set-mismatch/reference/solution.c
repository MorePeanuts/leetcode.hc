int *findErrorNums(int *nums, int n, int *returnSize) {
    bool seen[n + 1];
    memset(seen, 0, sizeof(seen));
    int total = 0;
    int duplicate = 0;
    for (int i = 0; i < n; i++) {
        int value = nums[i];
        total += value;
        if (seen[value]) {
            duplicate = value;
        }
        seen[value] = true;
    }
    int missing = n * (n + 1) / 2 - total + duplicate;
    *returnSize = 2;
    int *result = malloc(2 * sizeof(*result));
    result[0] = duplicate;
    result[1] = missing;
    return result;
}
