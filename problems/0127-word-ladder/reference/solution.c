#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "uthash.h"

typedef struct {
    char key[11];
    int head;
    UT_hash_handle hh;
} Bucket;

typedef struct {
    int word;
    int next;
} Edge;

int ladderLength(char* beginWord, char* endWord, char** wordList, int wordListSize) {
    int end = -1;
    for (int i = 0; i < wordListSize; i++)
        if (strcmp(wordList[i], endWord) == 0) end = i;
    if (end < 0) return 0;

    int width = strlen(beginWord);
    size_t limit = (size_t)width * wordListSize;
    Bucket* index = NULL;
    Bucket* buckets = malloc(limit * sizeof(*buckets));
    Edge* edges = malloc(limit * sizeof(*edges));
    int bucketCount = 0;
    int edgeCount = 0;
    char pattern[11]; // Word lengths are at most 10.
    for (int i = 0; i < wordListSize; i++) {
        memcpy(pattern, wordList[i], (size_t)width + 1);
        for (int j = 0; j < width; j++) {
            pattern[j] = '*';
            Bucket* bucket;
            HASH_FIND_STR(index, pattern, bucket);
            if (!bucket) {
                bucket = &buckets[bucketCount++];
                memcpy(bucket->key, pattern, (size_t)width + 1);
                bucket->head = -1;
                HASH_ADD_STR(index, key, bucket);
            }
            edges[edgeCount] = (Edge){i, bucket->head};
            bucket->head = edgeCount++;
            pattern[j] = wordList[i][j];
        }
    }

    int* queue = malloc((size_t)(wordListSize + 1) * sizeof(*queue));
    bool* seen = calloc((size_t)wordListSize, sizeof(*seen));
    queue[0] = -1;
    int tail = 1;
    int distance = 1;
    int answer = 0;
    for (int head = 0; head < tail && answer == 0; distance++) {
        int levelEnd = tail;
        for (; head < levelEnd; head++) {
            int id = queue[head];
            if (id == end) {
                answer = distance;
                break;
            }
            const char* word = id < 0 ? beginWord : wordList[id];
            memcpy(pattern, word, (size_t)width + 1);
            for (int j = 0; j < width; j++) {
                pattern[j] = '*';
                Bucket* bucket;
                HASH_FIND_STR(index, pattern, bucket);
                if (bucket) {
                    for (int edge = bucket->head; edge >= 0; edge = edges[edge].next) {
                        int next = edges[edge].word;
                        if (!seen[next]) {
                            seen[next] = true;
                            queue[tail++] = next;
                        }
                    }
                    bucket->head = -1;
                }
                pattern[j] = word[j];
            }
        }
    }
    HASH_CLEAR(hh, index);
    free(seen);
    free(queue);
    free(edges);
    free(buckets);
    return answer;
}
