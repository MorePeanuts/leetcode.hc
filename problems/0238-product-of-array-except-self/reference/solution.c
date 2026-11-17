#include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int n = numsSize;
    int* result = malloc((size_t)n * sizeof(*result));
    *returnSize = n;
    int prefix = 1;
    for (int i = 0; i < n; i++) {
        result[i] = prefix;
        prefix *= nums[i];
    }
    int suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
        result[i] *= suffix;
        suffix *= nums[i];
    }
    return result;
}
