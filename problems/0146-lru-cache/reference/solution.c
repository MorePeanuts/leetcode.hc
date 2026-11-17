#include <stdlib.h>
#include "uthash.h"

typedef struct Entry {
    int key;
    int value;
    struct Entry* previous;
    struct Entry* next;
    UT_hash_handle hh;
} Entry;

typedef struct {
    int capacity;
    Entry* entries;
    Entry sentinel;
} LRUCache;

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* cache = calloc(1, sizeof(*cache));
    cache->capacity = capacity;
    cache->sentinel.next = cache->sentinel.previous = &cache->sentinel;
    return cache;
}

static void unlinkEntry(Entry* entry) {
    entry->previous->next = entry->next;
    entry->next->previous = entry->previous;
}

static void appendEntry(LRUCache* cache, Entry* entry) {
    Entry* end = &cache->sentinel;
    entry->previous = end->previous;
    entry->next = end;
    entry->previous->next = entry;
    end->previous = entry;
}

int lRUCacheGet(LRUCache* cache, int key) {
    Entry* entry;
    HASH_FIND_INT(cache->entries, &key, entry);
    if (!entry) return -1;
    unlinkEntry(entry);
    appendEntry(cache, entry);
    return entry->value;
}

void lRUCachePut(LRUCache* cache, int key, int value) {
    Entry* entry;
    HASH_FIND_INT(cache->entries, &key, entry);
    if (entry) {
        unlinkEntry(entry);
    } else {
        if (HASH_COUNT(cache->entries) == (unsigned)cache->capacity) {
            entry = cache->sentinel.next;
            unlinkEntry(entry);
            HASH_DEL(cache->entries, entry);
        } else {
            entry = malloc(sizeof(*entry));
        }
        entry->key = key;
        HASH_ADD_INT(cache->entries, key, entry);
    }
    entry->value = value;
    appendEntry(cache, entry);
}

void lRUCacheFree(LRUCache* cache) {
    Entry* entry;
    Entry* next;
    HASH_ITER(hh, cache->entries, entry, next) {
        HASH_DEL(cache->entries, entry);
        free(entry);
    }
    free(cache);
}
