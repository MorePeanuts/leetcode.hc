char* longestPalindrome(char* s) {
    int n = (int)strlen(s);
    int start = 0;
    int length = 1;
    for (int center = 0; center < 2 * n - 1; ++center) {
        int left = center >> 1;
        int right = (center + 1) >> 1;
        while (left >= 0 && right < n && s[left] == s[right]) {
            --left;
            ++right;
        }
        if (right - left - 1 > length) {
            start = left + 1;
            length = right - left - 1;
        }
    }
    char* result = malloc((size_t)length + 1);
    memcpy(result, s + start, (size_t)length);
    result[length] = 0;
    return result;
}
