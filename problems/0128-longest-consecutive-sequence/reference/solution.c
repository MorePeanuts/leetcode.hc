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


int longestConsecutive(int *nums, int n) {
    Entry *entries = NULL;
    for (int i = 0; i < n; i++) {
        setEntry(&entries, nums[i], 1);
    }
    int best = 0;
    Entry *entry, *next;
    HASH_ITER(hh, entries, entry, next) {
        int key = entry->key;
        int length = 1;
        Entry *found;
        if (key > INT_MIN) {
            int previous = key - 1;
            HASH_FIND_INT(entries, &previous, found);
            if (found != NULL) {
                continue;
            }
        }
        while (key < INT_MAX) {
            key++;
            HASH_FIND_INT(entries, &key, found);
            if (found == NULL) {
                break;
            }
            length++;
        }
        if (length > best) {
            best = length;
        }
    }
    freeEntries(entries);
    return best;
}
