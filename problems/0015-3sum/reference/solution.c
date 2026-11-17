static int compareInt(const void *left, const void *right) {
    int a = *(const int *)left;
    int b = *(const int *)right;
    return (a > b) - (a < b);
}

int **threeSum(int *nums, int n, int *returnSize, int **returnColumnSizes) {
    qsort(nums, n, sizeof(*nums), compareInt);
    int capacity = 0;
    int **result = NULL;
    *returnSize = 0;
    *returnColumnSizes = NULL;

    for (int i = 0; i + 2 < n && nums[i] <= 0; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        int left = i + 1;
        int right = n - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum < 0) {
                left++;
            } else if (sum > 0) {
                right--;
            } else {
                if (*returnSize == capacity) {
                    capacity = capacity == 0 ? 16 : capacity * 2;
                    result = realloc(result, capacity * sizeof(*result));
                    *returnColumnSizes = realloc(*returnColumnSizes, capacity * sizeof(**returnColumnSizes));
                }
                int *triplet = malloc(3 * sizeof(*triplet));
                triplet[0] = nums[i];
                triplet[1] = nums[left];
                triplet[2] = nums[right];
                result[*returnSize] = triplet;
                (*returnColumnSizes)[*returnSize] = 3;
                ++*returnSize;
                int lower = nums[left];
                int upper = nums[right];
                while (left < right && nums[left] == lower) {
                    left++;
                }
                while (left < right && nums[right] == upper) {
                    right--;
                }
            }
        }
    }
    return result;
}
