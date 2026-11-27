bool canReach(int* arr, int arrSize, int start) {
    bool *seen = calloc(arrSize, sizeof(*seen));
    int *stack = malloc(arrSize * sizeof(*stack));
    int size = 0;
    stack[size++] = start;
    seen[start] = true;
    bool found = false;
    while (size > 0) {
        int i = stack[--size];
        if (arr[i] == 0) {
            found = true;
            break;
        }
        int neighbors[] = {i - arr[i], i + arr[i]};
        for (int direction = 0; direction < 2; direction++) {
            int j = neighbors[direction];
            if (j >= 0 && j < arrSize && !seen[j]) {
                seen[j] = true;
                stack[size++] = j;
            }
        }
    }
    free(stack);
    free(seen);
    return found;
}
