#include <stdlib.h>
#include "uthash.h"

typedef struct {
    int sum;
    int count;
    UT_hash_handle hh;
} Entry;

int subarraySum(int* nums, int numsSize, int k) {
    Entry* seen = NULL;
    Entry* entries = malloc((size_t)(numsSize + 1) * sizeof(*entries));
    int count = 1;
    entries[0].sum = 0;
    entries[0].count = 1;
    HASH_ADD_INT(seen, sum, &entries[0]);
    int prefix = 0;
    int answer = 0;
    for (int i = 0; i < numsSize; i++) {
        prefix += nums[i];
        int wanted = prefix - k;
        Entry* entry;
        HASH_FIND_INT(seen, &wanted, entry);
        if (entry) answer += entry->count;
        HASH_FIND_INT(seen, &prefix, entry);
        if (entry) {
            entry->count++;
        } else {
            entry = &entries[count++];
            entry->sum = prefix;
            entry->count = 1;
            HASH_ADD_INT(seen, sum, entry);
        }
    }
    HASH_CLEAR(hh, seen);
    free(entries);
    return answer;
}
