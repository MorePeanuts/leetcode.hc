#include <stdbool.h>
#include <stdlib.h>
#include "uthash.h"

typedef struct {
    int key;
    int last;
    UT_hash_handle hh;
} Entry;

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    Entry* last = NULL;
    Entry* entries = malloc((size_t)numsSize * sizeof(*entries));
    int count = 0;
    bool found = false;
    for (int i = 0; i < numsSize; i++) {
        Entry* entry;
        HASH_FIND_INT(last, &nums[i], entry);
        if (entry) {
            if (i - entry->last <= k) {
                found = true;
                break;
            }
        } else {
            entry = &entries[count++];
            entry->key = nums[i];
            HASH_ADD_INT(last, key, entry);
        }
        entry->last = i;
    }
    HASH_CLEAR(hh, last);
    free(entries);
    return found;
}
