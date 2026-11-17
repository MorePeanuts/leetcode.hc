#include <stdlib.h>
#include <string.h>
#include "uthash.h"

typedef struct {
    char key[101];
    int index;
    int capacity;
    UT_hash_handle hh;
} Group;

static int compareChars(const void* lhs, const void* rhs) {
    return *(const unsigned char*)lhs - *(const unsigned char*)rhs;
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    Group* groups = NULL;
    char*** result = malloc((size_t)strsSize * sizeof(*result));
    int* lengths = malloc((size_t)strsSize * sizeof(*lengths));
    int count = 0;
    for (int i = 0; i < strsSize; i++) {
        char key[101]; // |strs[i]| <= 100
        size_t length = strlen(strs[i]);
        memcpy(key, strs[i], length + 1);
        qsort(key, length, sizeof(*key), compareChars);
        Group* group;
        HASH_FIND_STR(groups, key, group);
        if (!group) {
            group = malloc(sizeof(*group));
            memcpy(group->key, key, length + 1);
            group->index = count++;
            group->capacity = 1;
            result[group->index] = malloc(sizeof(**result));
            lengths[group->index] = 0;
            HASH_ADD_STR(groups, key, group);
        }
        int index = group->index;
        if (lengths[index] == group->capacity) {
            group->capacity *= 2;
            result[index] = realloc(result[index], (size_t)group->capacity * sizeof(**result));
        }
        result[index][lengths[index]++] = strs[i];
    }
    Group* group;
    Group* next;
    HASH_ITER(hh, groups, group, next) {
        HASH_DEL(groups, group);
        free(group);
    }
    *returnSize = count;
    *returnColumnSizes = lengths;
    return result;
}
