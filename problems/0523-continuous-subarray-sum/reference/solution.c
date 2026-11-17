typedef struct {
    int key;
    int value;
    UT_hash_handle hh;
} Entry;

static Entry *setEntry(Entry **entries, int key, int value) {
    Entry *entry;
    HASH_FIND_INT(*entries, &key, entry);
    if (entry == NULL) {
        entry = malloc(sizeof(*entry));
        entry->key = key;
        HASH_ADD_INT(*entries, key, entry);
    }
    entry->value = value;
    return entry;
}

static void freeEntries(Entry *entries) {
    Entry *entry, *next;
    HASH_ITER(hh, entries, entry, next) {
        HASH_DEL(entries, entry);
        free(entry);
    }
}


bool checkSubarraySum(int *nums, int n, int k) {
    Entry *first = NULL;
    setEntry(&first, 0, -1);
    int remainder = 0;
    bool found = false;
    for (int i = 0; i < n; i++) {
        remainder = ((long long)remainder + nums[i]) % k;
        Entry *entry;
        HASH_FIND_INT(first, &remainder, entry);
        if (entry == NULL) {
            setEntry(&first, remainder, i);
        } else if (i - entry->value >= 2) {
            found = true;
            break;
        }
    }
    freeEntries(first);
    return found;
}
