#include <stdlib.h>
#include <string.h>

char* reverseWords(char* s) {
    size_t end = strlen(s);
    char* result = malloc(end + 1);
    size_t length = 0;
    while (end > 0) {
        while (end > 0 && s[end - 1] == ' ') end--;
        if (end == 0) break;
        size_t start = end;
        while (start > 0 && s[start - 1] != ' ') start--;
        if (length != 0) result[length++] = ' ';
        memcpy(result + length, s + start, end - start);
        length += end - start;
        end = start;
    }
    result[length] = '\0';
    return result;
}
