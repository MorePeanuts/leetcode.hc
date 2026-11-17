int *maxSlidingWindow(int *nums, int n, int k, int *returnSize) {
    *returnSize = n - k + 1;
    int *result = malloc(*returnSize * sizeof(*result));
    int *queue = malloc(n * sizeof(*queue));
    int head = 0;
    int tail = 0;
    for (int i = 0; i < n; i++) {
        while (tail > head && nums[queue[tail - 1]] <= nums[i]) {
            tail--;
        }
        queue[tail++] = i;
        if (queue[head] <= i - k) {
            head++;
        }
        if (i >= k - 1) {
            result[i - k + 1] = nums[queue[head]];
        }
    }
    free(queue);
    return result;
}
