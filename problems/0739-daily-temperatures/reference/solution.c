int *dailyTemperatures(int *temperatures, int n, int *returnSize) {
    *returnSize = n;
    int *result = malloc(n * sizeof(*result));
    int *stack = malloc(n * sizeof(*stack));
    int size = 0;
    for (int i = n - 1; i >= 0; i--) {
        while (size > 0 && temperatures[stack[size - 1]] <= temperatures[i]) {
            size--;
        }
        result[i] = size == 0 ? 0 : stack[size - 1] - i;
        stack[size++] = i;
    }
    free(stack);
    return result;
}
