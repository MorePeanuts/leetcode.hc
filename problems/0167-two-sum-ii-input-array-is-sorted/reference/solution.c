#include <stdlib.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int left = 0;
    int right = numbersSize - 1;
    while (left < right) {
        long long sum = (long long)numbers[left] + numbers[right];
        if (sum == target) {
            int* result = malloc(2 * sizeof(*result));
            result[0] = left + 1;
            result[1] = right + 1;
            *returnSize = 2;
            return result;
        }
        if (sum < target) left++;
        else right--;
    }
    *returnSize = 0;
    return NULL;
}
