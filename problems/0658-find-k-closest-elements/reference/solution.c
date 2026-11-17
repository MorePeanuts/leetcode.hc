#include <stdlib.h>
#include <string.h>

int* findClosestElements(int* arr, int arrSize, int k, int x, int* returnSize) {
    int left = 0;
    int right = arrSize - k;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (x - arr[mid] > arr[mid + k] - x) left = mid + 1;
        else right = mid;
    }
    int* result = malloc((size_t)k * sizeof(*result));
    memcpy(result, arr + left, (size_t)k * sizeof(*result));
    *returnSize = k;
    return result;
}
