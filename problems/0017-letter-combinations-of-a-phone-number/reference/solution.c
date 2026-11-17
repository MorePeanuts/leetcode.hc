static const char* const keypad[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

static void visit(const char* digits, int index, int len, char* path, char** result, int* size) {
    if (index == len) {
        char* value = malloc((size_t)len + 1);
        memcpy(value, path, (size_t)len);
        value[len] = 0;
        result[(*size)++] = value;
        return;
    }
    const char* options = keypad[digits[index] - '2'];
    for (int i = 0; options[i]; ++i) {
        path[index] = options[i];
        visit(digits, index + 1, len, path, result, size);
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    int len = (int)strlen(digits);
    int count = 1;
    for (int i = 0; i < len; ++i) {
        count *= (int)strlen(keypad[digits[i] - '2']);
    }
    char** result = malloc((size_t)count * sizeof(*result));
    char* path = malloc((size_t)len + 1);
    *returnSize = 0;
    visit(digits, 0, len, path, result, returnSize);
    free(path);
    return result;
}
