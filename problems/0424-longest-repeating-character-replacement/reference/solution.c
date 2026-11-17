int characterReplacement(char* s, int k) {
    int* count = calloc((size_t)(26), sizeof(*count));
    int most = 0;
    int left = 0;
    int n = (int)strlen(s);
    for (int right = 0; right < n; ++right) {
        int frequency = ++count[(s[right]) - ('A')];
        if (frequency > most) {
            most = frequency;
        }
        if (right - left + 1 - most > k) {
            --count[(s[left]) - ('A')];
            ++left;
        }
    }
    free(count);
    return n - left;
}
