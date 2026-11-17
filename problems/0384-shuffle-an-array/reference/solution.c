#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int original[50];
    int size;
    uint32_t state;
} Solution;

static uint32_t randomValue(Solution* solution) {
    uint32_t value = solution->state;
    value ^= value << 13;
    value ^= value >> 17;
    value ^= value << 5;
    solution->state = value;
    return value;
}

Solution* solutionCreate(int* nums, int numsSize) {
    Solution* solution = malloc(sizeof(*solution));
    solution->size = numsSize;
    memcpy(solution->original, nums, (size_t)numsSize * sizeof(*nums));
    struct timespec timePoint = {0};
    timespec_get(&timePoint, TIME_UTC);
    solution->state = ((uint32_t)timePoint.tv_nsec ^ (uint32_t)timePoint.tv_sec) | 1U;
    return solution;
}

int* solutionReset(Solution* solution, int* returnSize) {
    *returnSize = solution->size;
    int* result = malloc((size_t)solution->size * sizeof(*result));
    memcpy(result, solution->original, (size_t)solution->size * sizeof(*result));
    return result;
}

int* solutionShuffle(Solution* solution, int* returnSize) {
    int* result = solutionReset(solution, returnSize);
    for (uint32_t i = (uint32_t)solution->size - 1; i > 0; i--) {
        uint32_t bound = i + 1;
        uint32_t limit = UINT32_MAX - UINT32_MAX % bound;
        uint32_t choice;
        do {
            choice = randomValue(solution);
        } while (choice > limit);
        uint32_t j = choice % bound;
        int old = result[i];
        result[i] = result[j];
        result[j] = old;
    }
    return result;
}

void solutionFree(Solution* solution) {
    free(solution);
}
