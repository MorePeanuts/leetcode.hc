int *partitionLabels(char *s, int *returnSize) {
    int n = strlen(s);
    int last[26] = {0};
    *returnSize = 0;
    int *result = malloc(26 * sizeof(*result));
    for (int i = 0; i < n; i++) {
        last[s[i] - 'a'] = i;
    }
    int start = 0;
    int end = 0;
    for (int i = 0; i < n; i++) {
        int latest = last[s[i] - 'a'];
        if (latest > end) {
            end = latest;
        }
        if (i == end) {
            result[(*returnSize)++] = (end - start + 1);
            start = i + 1;
        }
    }
    return result;
}
