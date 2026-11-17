#include <stdlib.h>
#include <string.h>

int* findAnagrams(char* s, char* p, int* returnSize) {
    int n = strlen(s);
    int m = strlen(p);
    int need[26] = {0};
    int window[26] = {0};
    int* result = malloc((size_t)n * sizeof(*result));
    *returnSize = 0;
    for (int i = 0; i < m; i++) need[p[i] - 'a']++;
    for (int right = 0; right < n; right++) {
        window[s[right] - 'a']++;
        if (right >= m) window[s[right - m] - 'a']--;
        if (right + 1 >= m && memcmp(window, need, sizeof(need)) == 0) result[(*returnSize)++] = right + 1 - m;
    }
    return result;
}
