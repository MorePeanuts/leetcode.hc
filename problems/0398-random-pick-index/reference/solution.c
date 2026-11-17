typedef struct {
    int value;
    int *indices;
    int count;
    int used;
    UT_hash_handle hh;
} Entry;

typedef struct {
    Entry *positions;
} Solution;

// Rejection removes the bias from reducing to a smaller range.
static int uniformIndex(int count) {
    unsigned long long base = (unsigned long long)RAND_MAX + 1;
    unsigned long long range = base * base;
    unsigned long long limit = range - range % (unsigned int)count;
    unsigned long long draw;
    do {
        unsigned long long high = rand();
        unsigned long long low = rand();
        draw = high * base + low;
    } while (draw >= limit);
    return draw % (unsigned int)count;
}

Solution *solutionCreate(int *nums, int numsSize) {
    Solution *obj = calloc(1, sizeof(*obj));
    Entry *entry, *next;
    for (int i = 0; i < numsSize; i++) {
        HASH_FIND_INT(obj->positions, &nums[i], entry);
        if (entry == NULL) {
            entry = calloc(1, sizeof(*entry));
            entry->value = nums[i];
            HASH_ADD_INT(obj->positions, value, entry);
        }
        entry->count++;
    }
    HASH_ITER(hh, obj->positions, entry, next) {
        entry->indices = malloc(entry->count * sizeof(*entry->indices));
    }
    for (int i = 0; i < numsSize; i++) {
        HASH_FIND_INT(obj->positions, &nums[i], entry);
        entry->indices[entry->used++] = i;
    }
    return obj;
}

int solutionPick(Solution *obj, int target) {
    Entry *entry;
    HASH_FIND_INT(obj->positions, &target, entry);
    return entry->indices[uniformIndex(entry->count)];
}

void solutionFree(Solution *obj) {
    Entry *entry, *next;
    HASH_ITER(hh, obj->positions, entry, next) {
        HASH_DEL(obj->positions, entry);
        free(entry->indices);
        free(entry);
    }
    free(obj);
}
