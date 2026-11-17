#include <stdint.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int size;
    uint32_t state;
    int prefix[];
} Solution;

static uint32_t nextRandom(Solution* obj) {
    uint32_t value = obj->state;
    value ^= value << 13;
    value ^= value >> 17;
    value ^= value << 5;
    obj->state = value;
    return value;
}

Solution* solutionCreate(int* w, int wSize) {
    Solution* obj = malloc(sizeof(*obj) + (size_t)wSize * sizeof(*obj->prefix));
    obj->size = wSize;
    int sum = 0;
    for (int i = 0; i < wSize; i++) {
        sum += w[i];
        obj->prefix[i] = sum;
    }
    struct timespec current = {0};
    timespec_get(&current, TIME_UTC);
    obj->state = ((uint32_t)current.tv_nsec ^ (uint32_t)current.tv_sec) | 1U;
    return obj;
}

int solutionPickIndex(Solution* obj) {
    uint32_t total = (uint32_t)obj->prefix[obj->size - 1];
    uint32_t limit = UINT32_MAX - UINT32_MAX % total;
    uint32_t random;
    do {
        random = nextRandom(obj);
    } while (random > limit);
    int target = (int)(random % total);
    int lo = 0, hi = obj->size - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (obj->prefix[mid] <= target) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

void solutionFree(Solution* obj) { free(obj); }
