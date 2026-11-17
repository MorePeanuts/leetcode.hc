#include <stdlib.h>
#include <string.h>

static void generate(int n, int opened, int closed, char* path, char** result, int* count) {
    int length = opened + closed;
    if (closed == n) {
        path[length] = '\0';
        char* value = malloc((size_t)length + 1);
        memcpy(value, path, (size_t)length + 1);
        result[(*count)++] = value;
        return;
    }
    if (opened < n) {
        path[length] = '(';
        generate(n, opened + 1, closed, path, result, count);
    }
    if (closed < opened) {
        path[length] = ')';
        generate(n, opened, closed + 1, path, result, count);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    // C(i+1) = C(i) * 2 * (2*i + 1) / (i + 2).
    int capacity = 1;
    for (int i = 0; i < n; i++) capacity = capacity * 2 * (2 * i + 1) / (i + 2);
    char** result = malloc((size_t)capacity * sizeof(*result));
    char path[17]; // n <= 8
    *returnSize = 0;
    generate(n, 0, 0, path, result, returnSize);
    return result;
}
