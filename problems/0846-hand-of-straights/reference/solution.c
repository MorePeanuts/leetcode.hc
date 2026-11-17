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

static int compareInt(const void *a, const void *b) {
    int left = *(const int *)a;
    int right = *(const int *)b;
    return (left > right) - (left < right);
}

bool isNStraightHand(int *hand, int n, int groupSize) {
    if (n % groupSize != 0) {
        return false;
    }
    Entry *counts = NULL;
    for (int i = 0; i < n; i++) {
        Entry *entry;
        HASH_FIND_INT(counts, &hand[i], entry);
        if (entry == NULL) {
            setEntry(&counts, hand[i], 1);
        } else {
            entry->value++;
        }
    }
    qsort(hand, n, sizeof(*hand), compareInt);
    bool possible = true;
    for (int i = 0; i < n && possible; i++) {
        Entry *entry;
        HASH_FIND_INT(counts, &hand[i], entry);
        int amount = entry->value;
        if (amount == 0) {
            continue;
        }
        for (int value = hand[i]; value < hand[i] + groupSize; value++) {
            HASH_FIND_INT(counts, &value, entry);
            if (entry == NULL || entry->value < amount) {
                possible = false;
                break;
            }
            entry->value -= amount;
        }
    }
    freeEntries(counts);
    return possible;
}
