bool wordPattern(char *pattern, char *s) {
    char *words[26] = {0};
    char *word = strtok(s, " ");
    for (int i = 0; pattern[i] != '\0'; i++) {
        if (word == NULL) {
            return false;
        }
        int letter = pattern[i] - 'a';
        if (words[letter] == NULL) {
            for (int j = 0; j < 26; j++) {
                if (words[j] != NULL && strcmp(words[j], word) == 0) {
                    return false;
                }
            }
            words[letter] = word;
        } else if (strcmp(words[letter], word) != 0) {
            return false;
        }
        word = strtok(NULL, " ");
    }
    return word == NULL;
}
