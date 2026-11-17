typedef struct {
    int timestamp;
    char* value;
} Value;

typedef struct {
    char* key;
    Value* entries;
    int count;
    int capacity;
    UT_hash_handle hh;
} History;

typedef struct {
    History* histories;
} TimeMap;

static char* copyString(const char* value) {
    size_t size = strlen(value) + 1;
    char* copy = malloc(size);
    memcpy(copy, value, size);
    return copy;
}

TimeMap* timeMapCreate(void) {
    return calloc(1, sizeof(TimeMap));
}

void timeMapSet(TimeMap* obj, char* key, char* value, int timestamp) {
    History* history;
    HASH_FIND_STR(obj->histories, key, history);
    if (history == NULL) {
        history = calloc(1, sizeof(*history));
        history->key = copyString(key);
        HASH_ADD_KEYPTR(hh, obj->histories, history->key, strlen(history->key), history);
    }
    if (history->count == history->capacity) {
        history->capacity = history->capacity == 0 ? 4 : history->capacity * 2;
        history->entries = realloc(history->entries, (size_t)history->capacity * sizeof(*history->entries));
    }
    history->entries[history->count++] = (Value){timestamp, copyString(value)};
}

char* timeMapGet(TimeMap* obj, char* key, int timestamp) {
    History* history;
    HASH_FIND_STR(obj->histories, key, history);
    if (history == NULL) {
        return "";
    }
    int left = 0;
    int right = history->count;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (history->entries[mid].timestamp <= timestamp) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left == 0 ? "" : history->entries[left - 1].value;
}

void timeMapFree(TimeMap* obj) {
    History* history;
    History* next;
    HASH_ITER(hh, obj->histories, history, next) {
        HASH_DEL(obj->histories, history);
        for (int i = 0; i < history->count; ++i) {
            free(history->entries[i].value);
        }
        free(history->entries);
        free(history->key);
        free(history);
    }
    free(obj);
}
