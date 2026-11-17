typedef struct {
    int value;
    UT_hash_handle hh;
} Entry;

bool containsDuplicate(int* nums, int numsSize) {
    Entry* entries = malloc((size_t)numsSize * sizeof(*entries));
    Entry* seen = NULL;
    bool duplicate = false;
    for (int i = 0; i < numsSize; ++i) {
        Entry* match;
        HASH_FIND_INT(seen, &nums[i], match);
        if (match != NULL) {
            duplicate = true;
            break;
        }
        Entry* entry = &entries[i];
        entry->value = nums[i];
        HASH_ADD_INT(seen, value, entry);
    }
    HASH_CLEAR(hh, seen);
    free(entries);
    return duplicate;
}
