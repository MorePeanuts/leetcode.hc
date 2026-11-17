typedef struct {
    int value;
    int index;
    UT_hash_handle hh;
} SeenValue;

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 0;
    SeenValue* entries = malloc((size_t)numsSize * sizeof(*entries));
    if (entries == NULL) {
        return NULL;
    }

    SeenValue* seen = NULL;
    int* answer = NULL;
    for (int i = 0; i < numsSize; ++i) {
        int complement = target - nums[i];
        SeenValue* match;
        HASH_FIND_INT(seen, &complement, match);
        if (match != NULL) {
            answer = malloc(2 * sizeof(*answer));
            if (answer != NULL) {
                answer[0] = match->index;
                answer[1] = i;
                *returnSize = 2;
            }
            break;
        }

        SeenValue* entry;
        HASH_FIND_INT(seen, &nums[i], entry);
        if (entry == NULL) {
            entry = &entries[i];
            entry->value = nums[i];
            entry->index = i;
            HASH_ADD_INT(seen, value, entry);
        }
    }

    HASH_CLEAR(hh, seen);
    free(entries);
    return answer;
}
