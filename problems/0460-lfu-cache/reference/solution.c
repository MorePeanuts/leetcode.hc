#include <stdlib.h>

typedef struct {
    int value;
    int count;
    int previous;
    int next;
} Entry;

typedef struct {
    int first;
    int last;
} Group;

typedef struct {
    int capacity;
    int size;
    int minimum;
    Entry entries[100002]; // Key k maps to index k + 1; zero means absent.
    Group groups[200002]; // Frequency is bounded by the number of calls.
} LFUCache;

LFUCache* lFUCacheCreate(int capacity) {
    LFUCache* cache = calloc(1, sizeof(*cache));
    cache->capacity = capacity;
    return cache;
}

static void detach(LFUCache* cache, int id) {
    Entry* entry = &cache->entries[id];
    Group* group = &cache->groups[entry->count];
    if (entry->previous) cache->entries[entry->previous].next = entry->next;
    else group->first = entry->next;
    if (entry->next) cache->entries[entry->next].previous = entry->previous;
    else group->last = entry->previous;
}

static void append(LFUCache* cache, int id, int count) {
    Entry* entry = &cache->entries[id];
    Group* group = &cache->groups[count];
    entry->count = count;
    entry->previous = group->last;
    entry->next = 0;
    if (group->last) cache->entries[group->last].next = id;
    else group->first = id;
    group->last = id;
}

static void touch(LFUCache* cache, int id) {
    int count = cache->entries[id].count;
    detach(cache, id);
    if (cache->minimum == count && cache->groups[count].first == 0)
        cache->minimum++;
    append(cache, id, count + 1);
}

int lFUCacheGet(LFUCache* cache, int key) {
    int id = key + 1;
    if (cache->entries[id].count == 0) return -1;
    touch(cache, id);
    return cache->entries[id].value;
}

void lFUCachePut(LFUCache* cache, int key, int value) {
    int id = key + 1;
    if (cache->entries[id].count != 0) {
        cache->entries[id].value = value;
        touch(cache, id);
        return;
    }
    if (cache->size == cache->capacity) {
        int evicted = cache->groups[cache->minimum].first;
        detach(cache, evicted);
        cache->entries[evicted].count = 0;
    } else {
        cache->size++;
    }
    cache->entries[id].value = value;
    append(cache, id, 1);
    cache->minimum = 1;
}

void lFUCacheFree(LFUCache* cache) { free(cache); }
