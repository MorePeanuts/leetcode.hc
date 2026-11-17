#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "uthash.h"

typedef struct {
    const char* word;
    UT_hash_handle hh;
} Word;

bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    Word* words = NULL;
    Word* entries = malloc((size_t)wordDictSize * sizeof(*entries));
    int longest = 0;
    for (int i = 0; i < wordDictSize; i++) {
        entries[i].word = wordDict[i];
        int length = strlen(wordDict[i]);
        HASH_ADD_KEYPTR(hh, words, entries[i].word, length, &entries[i]);
        if (length > longest) longest = length;
    }
    int n = strlen(s);
    bool* possible = calloc((size_t)n + 1, sizeof(*possible));
    possible[0] = true;
    for (int end = 1; end <= n; end++) {
        int first = end > longest ? end - longest : 0;
        for (int start = first; start < end; start++) {
            if (!possible[start]) continue;
            Word* found;
            HASH_FIND(hh, words, s + start, end - start, found);
            if (found) {
                possible[end] = true;
                break;
            }
        }
    }
    bool result = possible[n];
    free(possible);
    HASH_CLEAR(hh, words);
    free(entries);
    return result;
}
