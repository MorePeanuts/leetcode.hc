#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    size_t length = 0;
    for (; strs[0][length]; length++) {
        int i = 1;
        while (i < strsSize && strs[i][length] == strs[0][length]) i++;
        if (i < strsSize) break;
    }
    char* prefix = malloc(length + 1);
    memcpy(prefix, strs[0], length);
    prefix[length] = '\0';
    return prefix;
}
