int lengthOfLongestSubstring(char* s) {
    int last[256] = {0};
    int start = 0;
    int best = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        unsigned char ch = (unsigned char)s[i];
        if (last[ch] > start) start = last[ch];
        last[ch] = i + 1;
        if (i + 1 - start > best) best = i + 1 - start;
    }
    return best;
}
