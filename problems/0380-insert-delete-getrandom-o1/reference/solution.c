typedef struct {
    int value;
    int index;
    UT_hash_handle hh;
} Entry;

typedef struct {
    int *values;
    int size;
    int capacity;
    Entry *positions;
} RandomizedSet;

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

RandomizedSet *randomizedSetCreate(void) {
    return calloc(1, sizeof(RandomizedSet));
}

bool randomizedSetInsert(RandomizedSet *obj, int val) {
    Entry *entry;
    HASH_FIND_INT(obj->positions, &val, entry);
    if (entry != NULL) {
        return false;
    }
    if (obj->size == obj->capacity) {
        obj->capacity = obj->capacity == 0 ? 16 : obj->capacity * 2;
        obj->values = realloc(obj->values, obj->capacity * sizeof(*obj->values));
    }
    entry = malloc(sizeof(*entry));
    *entry = (Entry){.value = val, .index = obj->size};
    HASH_ADD_INT(obj->positions, value, entry);
    obj->values[obj->size++] = val;
    return true;
}

bool randomizedSetRemove(RandomizedSet *obj, int val) {
    Entry *entry;
    HASH_FIND_INT(obj->positions, &val, entry);
    if (entry == NULL) {
        return false;
    }
    int last = obj->values[--obj->size];
    Entry *lastEntry;
    HASH_FIND_INT(obj->positions, &last, lastEntry);
    obj->values[entry->index] = last;
    lastEntry->index = entry->index;
    HASH_DEL(obj->positions, entry);
    free(entry);
    return true;
}

int randomizedSetGetRandom(RandomizedSet *obj) {
    return obj->values[uniformIndex(obj->size)];
}

void randomizedSetFree(RandomizedSet *obj) {
    Entry *entry, *next;
    HASH_ITER(hh, obj->positions, entry, next) {
        HASH_DEL(obj->positions, entry);
        free(entry);
    }
    free(obj->values);
    free(obj);
}
