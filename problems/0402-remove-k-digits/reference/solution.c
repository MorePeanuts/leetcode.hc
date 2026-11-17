char* removeKdigits(char* num, int k) {
    char* digits = malloc((size_t)strlen(num) + 1);
    int len = 0;
    int n = (int)strlen(num);
    for (int i = 0; i < n; ++i) {
        while (k > 0 && len > 0 && digits[len - 1] > num[i]) {
            --len;
            --k;
        }
        digits[len++] = num[i];
    }
    len -= k;
    int start = 0;
    while (start < len && digits[start] == '0') {
        ++start;
    }
    if (start == len) {
        digits[0] = '0';
        digits[1] = '\0';
    } else {
        memmove(digits, digits + start, (size_t)(len - start));
        digits[len - start] = '\0';
    }
    return digits;
}
