#include <stdbool.h>
#include <stdlib.h>

bool canPartition(int* nums, int numsSize) {
    int total = 0;
    for (int i = 0; i < numsSize; i++) total += nums[i];
    if (total % 2 != 0) return false;
    int target = total / 2;
    bool* possible = calloc((size_t)target + 1, sizeof(*possible));
    possible[0] = true;
    for (int i = 0; i < numsSize; i++) {
        int value = nums[i];
        for (int subtotal = target; subtotal >= value; subtotal--) {
            if (possible[subtotal - value]) possible[subtotal] = true;
        }
    }
    bool answer = possible[target];
    free(possible);
    return answer;
}
