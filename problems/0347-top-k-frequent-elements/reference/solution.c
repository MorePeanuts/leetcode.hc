typedef struct {
    int value;
    int frequency;
    UT_hash_handle hh;
} Count;

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    Count* entries = malloc((size_t)numsSize * sizeof(*entries));
    Count* counts = NULL;
    int used = 0;
    for (int i = 0; i < numsSize; ++i) {
        Count* entry;
        HASH_FIND_INT(counts, &nums[i], entry);
        if (entry == NULL) {
            entry = &entries[used++];
            entry->value = nums[i];
            entry->frequency = 0;
            HASH_ADD_INT(counts, value, entry);
        }
        ++entry->frequency;
    }
    int* first = calloc((size_t)numsSize + 1, sizeof(*first));
    int* next = malloc((size_t)used * sizeof(*next));
    for (int i = 0; i < used; ++i) {
        int frequency = entries[i].frequency;
        next[i] = first[frequency];
        first[frequency] = i + 1;
    }
    int* result = malloc((size_t)k * sizeof(*result));
    int size = 0;
    for (int frequency = numsSize; frequency > 0 && size < k; --frequency) {
        for (int id = first[frequency]; id > 0 && size < k; id = next[id - 1]) {
            result[size++] = entries[id - 1].value;
        }
    }
    HASH_CLEAR(hh, counts);
    free(entries);
    free(first);
    free(next);
    *returnSize = size;
    return result;
}
