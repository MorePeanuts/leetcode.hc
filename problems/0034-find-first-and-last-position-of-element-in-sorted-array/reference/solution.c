int *searchRange(int *nums, int n, int target, int *returnSize) {
    int low = 0;
    int high = n;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    int first = -1;
    int last = -1;
    if (low < n && nums[low] == target) {
        first = low;
        high = n;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        last = low - 1;
    }
    *returnSize = 2;
    int *result = malloc(2 * sizeof(*result));
    result[0] = first;
    result[1] = last;
    return result;
}
