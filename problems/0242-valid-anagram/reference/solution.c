bool isAnagram(char *s, char *t) {
    int m = strlen(s);
    int n = strlen(t);
    if (m != n) {
        return false;
    }
    int counts[26] = {0};
    for (int i = 0; i < n; i++) {
        counts[s[i] - 'a']++;
        counts[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
        if (counts[i] != 0) {
            return false;
        }
    }
    return true;
}
