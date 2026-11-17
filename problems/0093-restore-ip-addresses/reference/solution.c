static void visit(const char* s, int len, int start, int segments, char* path, int end, char** out, int* size) {
    int left = 4 - segments;
    if (len - start < left || len - start > 3 * left) {
        return;
    }
    if (left == 0) {
        char* address = malloc((size_t)end + 1);
        memcpy(address, path, (size_t)end);
        address[end] = 0;
        out[(*size)++] = address;
        return;
    }
    if (segments > 0) {
        path[end++] = '.';
    }
    int value = 0;
    for (int length = 1; length <= 3 && start + length <= len; ++length) {
        char digit = s[start + length - 1];
        value = value * 10 + digit - '0';
        if (value > 255 || (length > 1 && s[start] == '0')) {
            break;
        }
        path[end + length - 1] = digit;
        visit(s, len, start + length, segments + 1, path, end + length, out, size);
    }
}

char** restoreIpAddresses(char* s, int* returnSize) {
    // Each of the four segments has at most three possible lengths.
    char** result = malloc(81 * sizeof(*result));
    char path[16];
    *returnSize = 0;
    visit(s, (int)strlen(s), 0, 0, path, 0, result, returnSize);
    return result;
}
